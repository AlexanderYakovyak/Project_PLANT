#include <stdlib.h>
#include <stdio.h>
#include "PLANT.h"

/* Product test
input product from console
write this product to file "products.csv"
get this product from file "products.csv"
print information to console
@param - void
@result Ц  void
*/
void product_test(){
    Product p;
    printf("Input information about new product\n");
    p = get_product_from_console();
    add_product_to_file(p);
    printf("\n");

    Product p2;
    printf("Information about product with id %d \n", p.id);
    p2 = get_product_from_file(p.id);
    print_product_to_console(p2);
}

/* Equipment test
input equipment from console
write this equipment to file "equipments.csv"
get this equipment from file "equipments.csv"
print information to console
@param - void
@result Ц  void
*/
void equipment_test(){
    Equipment e;
    printf("Input information about new equipment\n");
    e = get_equipment_from_console();
    add_equipment_to_file(e);
    printf("\n");

    Equipment e2;
    printf("Information about equipment with id %d \n", e.id);
    e2 = get_equipment_from_file(e.id);
    print_equipment_to_console(e2);
}

/* Profession test
input profession from console
write this profession to file "professions.csv"
get this profession from file "professions.csv"
print information to console
@param - void
@result Ц  void
*/
void profession_test(){
    Profession p;
    printf("Input information about new profession\n");
    p = get_profession_from_console();
    add_profession_to_file(p);
    printf("\n");

    Profession p2;
    printf("Information about profession with id %d \n", p.id);
    p2 = get_profession_from_file(p.id);
    print_profession_to_console(p2);
}

/* Worker test
input worker from console
write this worker to file "workers.csv"
get this worker from file "workers.csv"
print information to console
@param - void
@result Ц  void
*/
void worker_test(){
    Worker w;
    printf("Input information about new worker\n");
    w = get_worker_from_console();
    add_worker_to_file(w);
    printf("\n");

    Worker w2;
    printf("Information about worker with id %d \n", w.id);
    w2 = get_worker_from_file(w.id);
    print_worker_to_console(w2);
}

/* Director test
input director from console
write this director to file "directors.csv"
get this director from file "directors.csv"
print information to console
@param - void
@result Ц  void
*/
void director_test(){
    Director d;
    printf("Input information about new director\n");
    d = get_director_from_console();
    add_director_to_file(d);
    printf("\n");

    Director d2;
    printf("Information about director with id %d \n", d.id);
    d2 = get_director_from_file(d.id);
    print_director_to_console(d2);
}


/* SideWorker test
input sideworker from console
write this sideworker to file "sideworkers.csv"
get this sideworker from file "sideworkers.csv"
print information to console
@param - void
@result Ц  void
*/
void sideworker_test(){
    SideWorker w;
    printf("Input information about new side worker\n");
    w = get_sideworker_from_console();
    add_sideworker_to_file(w);
    printf("\n");

    SideWorker w2;
    printf("Information about side worker with id %d \n", w.id);
    w2 = get_sideworker_from_file(w.id);
    print_sideworker_to_console(w2);
}

/* Workers salaries test
calculate salary of each worker in file "workers.csv"
print information to console
@param - void
@result Ц  void
*/
void workers_salaries(){
    char workers_file[] = "../workers.csv";
    int workers_ids = set_id(workers_file);

    for(int i=1;i<workers_ids;i++){
        Worker w;
        w = get_worker_from_file(i);
        calculate_worker_salary(w);
    }
}

/* SideWorkers salaries test
calculate salary of each sideworker in file "sideworkers.csv"
print information to console
@param - void
@result Ц  void
*/
void sideworkers_salaries(){
    char workers_file[] = "../sideworkers.csv";
    int workers_ids = set_id(workers_file);

    for(int i=1;i<workers_ids;i++){
        SideWorker w;
        w = get_sideworker_from_file(i);
        calculate_sideworker_salary(w);
    }
}

/* Directors salaries test
calculate salary of each director in file "directors.csv"
print information to console
@param - void
@result Ц  void
*/
void directors_salaries(){
    char directors_file[] = "../directors.csv";
    int directors_ids = set_id(directors_file);

    for(int i=1;i<directors_ids;i++){
        Director d;
        d = get_director_from_file(i);
        calculate_director_salary(d);
    }
}

/* Calculate cost of each equipment
from file "equipments.csv"
@param - void
@result Ц  void
*/
void all_equipment_cost(){
    char equipments_file[] = "../equipments.csv";
    int equipments_ids = set_id(equipments_file);

    for(int i=1;i<equipments_ids;i++){
        Equipment e;
        e = get_equipment_from_file(i);
        printf("Cost of equipment with id %d = %.4f", e.id, e.price);
    }

}

/* Calculate equipment total cost
Function that calculates total cost
of workers' equipment of a given director
@param - object of Director class
@result Ц  float value - equipment total cost
*/
float director_equipment_total_cost(Director d){
    float total_cost = 0;
    char workers_file[] = "../workers.csv";
    char siderworkers_file[] = "../sideworkers.csv";

    int workers_ids = set_id(workers_file);
    int sideworkers_ids = set_id(siderworkers_file);

    for(int i=1;i<workers_ids;i++){
        Worker w;
        w = get_worker_from_file(i);
        if(w.director_id==d.id){
            Equipment e;
            e = get_equipment_from_file(w.equipment_id);
            if(e.price){
                total_cost+=e.price;
            }
        }
    }

    for(int i=1;i<sideworkers_ids;i++){
        SideWorker w;
        w = get_sideworker_from_file(i);
        if(w.director_id==d.id){
            Equipment e;
            e = get_equipment_from_file(w.equipment_id);
            if(e.price){
                total_cost+=e.price;
            }
        }
    }

    return total_cost;
}

int main(){
    char i;

    /*–ахуЇмо варт≥сть обладнанн€ прац≥вник≥в,
    €к≥ п≥дпор€дкован≥ директору з ID=3
    та виводимо значенн€ в консоль
    */

    Director d2;
    d2 = get_director_from_file(3);
    printf("ID of this director %d", d2.id);
    float res = director_equipment_total_cost(d2);
    printf("Total cost of this director's workers' equipment = %.4f", res);

    /*“ут запускаютьс€ вс≥ вище описан≥ в цьому файл≥ тести,
    дл€ запуску будь-€кого з них просто прибер≥ть знак коментарю перед ними
    */

    //product_test();
    //equipment_test();
    //profession_test();
    //worker_test();
    //director_test();
    //sideworker_test();

    //workers_salaries();
    //sideworkers_salaries();
    //directors_salaries();

    //all_equipment_cost();


    scanf("%c", &i);
    scanf("%c", &i);
    return 0;
};
