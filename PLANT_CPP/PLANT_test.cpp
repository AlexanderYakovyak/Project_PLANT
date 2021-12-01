#include <iostream>
#include <string>
#include "PLANT.h"


/* Product test
input product from console
write this product to file "products.csv"
get this product from file "products.csv"
print information to console
@param - void
@result –  void
*/
void product_test(){
    Product p;
    cout<<"Input information about new product"<<endl;
    p.get_from_console();
    p.add_to_file();
    cout<<endl;

    Product p2;
    cout<<"Information about product with id "<<p.id<<endl;
    p2.get_from_file(p.id);
    p2.print_to_console();
}

/* Equipment test
input equipment from console
write this equipment to file "equipments.csv"
get this equipment from file "equipments.csv"
print information to console
@param - void
@result –  void
*/
void equipment_test(){
    Equipment e;
    cout<<"Input information about new equipment"<<endl;
    e.get_from_console();
    e.add_to_file();
    cout<<endl;

    Equipment e2;
    e2.get_from_file(e.id);
    cout<<"Information about equipment with id "<<e.id<<endl;
    e2.print_to_console();
}

/* Profession test
input profession from console
write this profession to file "professions.csv"
get this profession from file "professions.csv"
print information to console
@param - void
@result –  void
*/
void profession_test(){
    Profession p;
    cout<<"Input information about new profession"<<endl;
    p.get_from_console();
    p.add_to_file();
    cout<<endl;

    Profession p2;
    p2.get_from_file(p.id);
    cout<<"Information about profession with id "<<p.id<<endl;
    p2.print_to_console();
}

/* Worker test
input worker from console
write this worker to file "workers.csv"
get this worker from file "workers.csv"
print information to console
@param - void
@result –  void
*/
void worker_test(){
    Worker w;
    cout<<"Input information about new worker"<<endl;
    w.get_from_console();
    w.add_to_file();
    cout<<endl;

    Worker w2;
    w2.get_from_file(w.id);
    cout<<"Information about worker with id "<<w.id<<endl;
    w2.print_to_console();
}

/* Director test
input director from console
write this director to file "directors.csv"
get this director from file "directors.csv"
print information to console
@param - void
@result –  void
*/
void director_test(){
    Director d;
    cout<<"Input information about new director"<<endl;
    d.get_from_console();
    d.add_to_file();
    cout<<endl;

    Director d2;
    d2.get_from_file(d.id);
    cout<<"Information about director with id "<<d.id<<endl;
    d2.print_to_console();
}

/* SideWorker test
input sideworker from console
write this sideworker to file "sideworkers.csv"
get this sideworker from file "sideworkers.csv"
print information to console
@param - void
@result –  void
*/
void sideworker_test(){
    SideWorker s;
    cout<<"Input information about new sideworker"<<endl;
    s.get_from_console();
    s.add_to_file();
    cout<<endl;

    SideWorker s2;
    s2.get_from_file(s.id);
    cout<<"Information about sideworker with id "<<s.id<<endl;
    s2.print_to_console();
}

/* Workers salaries test
calculate salary of each worker in file "workers.csv"
print information to console
@param - void
@result –  void
*/
void workers_salaries(){
    int workers_ids = set_id("../workers.csv");

    for(int i=1;i<workers_ids;i++){
        Worker w;
        w.get_from_file(i);
        w.calculate_salary();
    }
}

/* SideWorkers salaries test
calculate salary of each sideworker in file "sideworkers.csv"
print information to console
@param - void
@result –  void
*/
void sideworkers_salaries(){
    int sideworkers_ids = set_id("../sideworkers.csv");

    for(int i=1;i<sideworkers_ids;i++){
        SideWorker w;
        w.get_from_file(i);
        w.calculate_salary();
    }
}

/* Directors salaries test
calculate salary of each director in file "directors.csv"
print information to console
@param - void
@result –  void
*/
void directors_salaries(){
    int directors_ids = set_id("../directors.csv");

    for(int i=1;i<directors_ids;i++){
        Director d;
        d .get_from_file(i);
        d.calculate_salary();
    }
}

/* Calculate cost of each equipment
from file "equipments.csv"
@param - void
@result –  void
*/
void all_equipment_cost(){
    int equipments_ids = set_id("../equipments.csv");

    for(int i=1;i<equipments_ids;i++){
        Equipment e;
        e.get_from_file(i);
        cout<<"Cost of equipment with id "<<e.id<<" = "<<e.price<<endl;
    }

}

/* Calculate equipment total cost
Function that calculates total cost
of workers' equipment of a given director
@param - object of Director class
@result –  float value - equipment total cost
*/
float director_equipment_total_cost(Director d){
    float total_cost = 0;
    int workers_ids = set_id("../workers.csv");
    int sideworkers_ids = set_id("../sideworkers.csv");

    for(int i=1;i<workers_ids;i++){
        Worker w;
        w.get_from_file(i);
        if(w.director_id==d.id){
            Equipment e;
            e.get_from_file(w.equipment_id);
            if(e.price){
                total_cost+=e.price;
            }
        }
    }

    for(int i=1;i<sideworkers_ids;i++){
        SideWorker sw;
        sw.get_from_file(i);
        if(sw.director_id==d.id){
            Equipment e;
            e.get_from_file(sw.equipment_id);
            if(e.price){
                total_cost+=e.price;
            }
        }
    }

    return total_cost;
}

int main(){
    string mode;

    /*Ðàõóºìî âàðò³ñòü îáëàäíàííÿ ïðàö³âíèê³â òà ñóì³ñíèê³â,
    ÿê³ ï³äïîðÿäêîâàí³ äèðåêòîðó ç ID=3
    òà âèâîäèìî çíà÷åííÿ â êîíñîëü
    */

    Director d2;
    d2.get_from_file(3);
    cout<<"Id of this director: "<<d2.id<<endl;
    cout<<"Total cost of this director's workers' equipment = ";
    cout<<director_equipment_total_cost(d2)<<endl;

    /*Òóò çàïóñêàþòüñÿ âñ³ âèùå îïèñàí³ â öüîìó ôàéë³ òåñòè,
    äëÿ çàïóñêó áóäü-ÿêîãî ç íèõ ïðîñòî ïðèáåð³òü çíàê êîìåíòàðþ ïåðåä íèìè
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



    cin>>mode;

}
