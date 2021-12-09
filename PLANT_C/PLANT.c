/* File PLANT.c
Realization of functions for task "Plant"
Done by Yakoviak Alexander (2.2 comp.math group)
Date 16.11.2021
Implementations of classes: Product, Equipment,
Profession, abstract class Human, Worker, Director
*/
#include "PLANT.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*function to automatically set an id for new object
of any class for writing to the file*/
int set_id(char filename[]){
    FILE* fp = fopen(filename, "r");
    int id = 0;
    char line[200];

    while (fgets(line,200,fp)) {
         char* value = strtok(line, ",");
         id++;
    }
    fclose(fp);

    return id;
}

/* Input product
input product from file
@param - id of the product to get
@result �  Product object
*/
Product get_product_from_file(int product_id){
    Product p;

    FILE* fp = fopen("../products.csv", "r");

    if (!fp)
        printf("Can't open file\n");

    else {
        char line[200];

        int row = 0;
        int column = 0;

        while (fgets(line,200,fp)) {
            column = 0;
            row++;

            if (row == 1)
                continue;

            char* value = strtok(line, ",");

            while (value) {
                int current_id;
                if (column==0){
                    current_id = atoi(value);
                }

                if (current_id==product_id){
                    if (column == 0) {
                        p.id = atoi(value);
                    }
                    else if (column == 1) {
                        strncpy(p.name,value,50);
                    }
                    else if (column == 2) {
                        p.cost_price = atof(value);
                    }
                    else if (column == 3) {
                        p.selling_price = atof(value);
                        printf("\n");
                    }
                }

                value = strtok(NULL, ",");
                column++;
            }
        }

        fclose(fp);
    }

    return p;
}

/* Output product
output product to file
@param - Product object
@result �  void
*/
void add_product_to_file(Product p){
    FILE* fp = fopen("../products.csv", "a+");

    if (!fp) {
        printf("Can't open file\n");
    }

    fprintf(fp, "%d,%s,%f,%f\n", p.id,p.name,
            p.cost_price, p.selling_price);
    fclose(fp);
}

/* Input product
input product from console
@param - void
@result �  Product object
*/
Product get_product_from_console(){
    Product p;

    char buffer[50];
    char*b = buffer;


    char filename[] = "../products.csv";
    p.id = set_id(filename);
    printf("Input product name: ");
    scanf("%[^\n]%*c", p.name);
    printf("Input product cost price: ");
    scanf("%f", &p.cost_price);
    printf("Input product selling price: ");
    scanf("%f", &p.selling_price);
    return p;
}

/* Output product
output product to console
@param - Product object
@result �  void
*/
void print_product_to_console(Product p){
    printf("Product id: %d \n", p.id);
    printf("Product name: %s \n", p.name);
    printf("Product cost price: %.3f \n", p.cost_price);
    printf("Product selling price: %.3f \n", p.selling_price);
}

/* Input equipment
input equipment from file
@param - id of the equipment to get
@result �  Equipment object
*/
Equipment get_equipment_from_file(int equipment_id){
    Equipment p;

    FILE* fp = fopen("../equipments.csv", "r");

    if (!fp)
        printf("Can't open file\n");

    else {
        char line[200];

        int row = 0;
        int column = 0;

        while (fgets(line,200,fp)) {
            column = 0;
            row++;

            if (row == 1)
                continue;

            char* value = strtok(line, ",");

            while (value) {
                int current_id;
                if (column==0){
                    current_id = atoi(value);
                }

                if (current_id==equipment_id){
                    if (column == 0) {
                        p.id = atoi(value);
                    }
                    else if (column == 1) {
                        strncpy(p.name,value,50);
                    }
                    else if (column == 2) {
                        p.price = atof(value);
                    }
                    else if (column == 3) {
                        p.product_id = atoi(value);
                        printf("\n");
                    }
                }

                value = strtok(NULL, ",");
                column++;
            }
        }

        fclose(fp);
    }

    return p;
}

/* Output equipment
output product to file
@param - Equipment object
@result �  void
*/
void add_equipment_to_file(Equipment p){
    FILE* fp = fopen("../equipments.csv", "a+");

    if (!fp) {
        printf("Can't open file\n");
    }

    fprintf(fp, "%d,%s,%f,%d\n", p.id,p.name,
            p.price, p.product_id);
    fclose(fp);
}

/* Input equipment
input equipment from console
@param - void
@result �  Equipment object
*/
Equipment get_equipment_from_console(){
    Equipment p;

    char buffer[50];
    char*b = buffer;

    char filename[] = "../equipments.csv";
    p.id = set_id(filename);
    printf("Input equipment name: ");
    scanf("%[^\n]%*c", p.name);
    printf("Input equipment price: ");
    scanf("%f", &p.price);
    printf("Input product ID made with this equipment: ");
    scanf("%d", &p.product_id);
    return p;
}

/* Output equipment
output equipment to console
@param - Equipment object
@result �  void
*/
void print_equipment_to_console(Equipment p){
    printf("Equipment id: %d \n", p.id);
    printf("Equipment name: %s \n", p.name);
    printf("Equipment price: %.3f \n", p.price);
    printf("Product ID made with this equipment: %d \n", p.product_id);
}

/* Input profession
input profession from file
@param - id of the profession to get
@result �  Profession object
*/
Profession get_profession_from_file(int profession_id){
    Profession p;

    FILE* fp = fopen("../professions.csv", "r");

    if (!fp)
        printf("Can't open file\n");

    else {
        char line[200];

        int row = 0;
        int column = 0;

        while (fgets(line,200,fp)) {
            column = 0;
            row++;

            if (row == 1)
                continue;

            char* value = strtok(line, ",");

            while (value) {
                int current_id;
                if (column==0){
                    current_id = atoi(value);
                }

                if (current_id==profession_id){
                    if (column == 0) {
                        p.id = atoi(value);
                    }
                    else if (column == 1) {
                        strncpy(p.name,value,50);
                    }
                    else if (column == 2) {
                        p.basic_rate = atof(value);
                    }
                }

                value = strtok(NULL, ",");
                column++;
            }
        }

        fclose(fp);
    }

    return p;
}

/* Output profession
output profession to file
@param - Profession object
@result �  void
*/
void add_profession_to_file(Profession p){
    FILE* fp = fopen("../professions.csv", "a+");

    if (!fp) {
        printf("Can't open file\n");
    }

    fprintf(fp, "%d,%s,%f\n", p.id,p.name, p.basic_rate);
    fclose(fp);
}

/* Input profession
input profession from console
@param - void
@result �  Profession object
*/
Profession get_profession_from_console(){
    Profession p;

    char buffer[50];
    char*b = buffer;

    char filename[] = "../professions.csv";
    p.id = set_id(filename);
    printf("Input profession name: ");
    scanf("%[^\n]%*c", p.name);
    printf("Input profession basic rate: ");
    scanf("%f", &p.basic_rate);

    return p;
}

/* Output profession
output profession to console
@param - Profession object
@result �  void
*/
void print_profession_to_console(Profession p){
    printf("Profession id: %d \n", p.id);
    printf("Profession name: %s \n", p.name);
    printf("Profession basic rate: %.3f \n", p.basic_rate);
}

/* Input worker
input worker from file
@param - id of the worker to get
@result �  Worker object
*/
Worker get_worker_from_file(int worker_id){
    Worker p;

    FILE* fp = fopen("../workers.csv", "r");

    if (!fp)
        printf("Can't open file\n");

    else {
        char line[200];

        int row = 0;
        int column = 0;

        while (fgets(line,200,fp)) {
            column = 0;
            row++;

            if (row == 1)
                continue;

            char* value = strtok(line, ",");

            while (value) {
                int current_id;
                if (column==0){
                    current_id = atoi(value);
                }

                if (current_id==worker_id){
                    if (column == 0) {
                        p.id = atoi(value);
                    }
                    else if (column == 1) {
                        strncpy(p.surname,value,50);
                    }
                    else if (column == 2) {
                        p.experience = atoi(value);
                    }
                    else if (column == 3) {
                        p.products_per_month = atoi(value);
                    }
                    else if (column == 4) {
                        p.equipment_id = atoi(value);
                    }
                    else if (column == 5) {
                        p.profession_id = atoi(value);
                    }
                    else if (column == 6) {
                        p.director_id = atoi(value);
                    }
                }

                value = strtok(NULL, ",");
                column++;
            }
        }

        fclose(fp);
    }

    return p;
}

/* Output worker
output worker to file
@param - Worker object
@result �  void
*/
void add_worker_to_file(Worker p){
    FILE* fp = fopen("../workers.csv", "a+");

    if (!fp) {
        printf("Can't open file\n");
    }

    fprintf(fp, "%d,%s,%d,%d,%d,%d,%d\n", p.id,p.surname, p.experience,
            p.products_per_month, p.equipment_id, p.profession_id,
            p.director_id);
    fclose(fp);
}

/* Input worker
input worker from console
@param - void
@result �  Worker object
*/
Worker get_worker_from_console(){
    Worker p;

    char buffer[50];
    char*b = buffer;

    char filename[] = "../workers.csv";
    p.id = set_id(filename);
    printf("Input worker surname: ");
    scanf("%[^\n]%*c", p.surname);
    printf("Input worker experience in years: ");
    scanf("%d", &p.experience);
    printf("Input number of products produced per month: ");
    scanf("%d", &p.products_per_month);
    printf("Input equipment ID used by worker: ");
    scanf("%d", &p.equipment_id);
    printf("Input profession ID of this worker: ");
    scanf("%d", &p.profession_id);
    printf("Input director ID of this worker: ");
    scanf("%d", &p.director_id);

    return p;
}

/* Output worker
output worker to console
@param - Worker object
@result �  void
*/
void print_worker_to_console(Worker p){
    printf("Worker id: %d \n", p.id);
    printf("Worker surname: %s \n", p.surname);
    printf("Worker experience: %d\n", p.experience);
    printf("Number of products produced per month: %d\n", p.products_per_month);
    printf("Equipment ID used by worker: %d\n", p.equipment_id);
    printf("Profession ID of this worker: %d\n", p.profession_id);
    printf("Director ID of this worker:: %d\n", p.director_id);
}

/* Calculate worker salary
based on experience,
profession basic rate, and
number of produced products
@param - Worker object
@result �  void
*/
void calculate_worker_salary(Worker w){

    Profession worker_profession;
    Equipment worker_equipment;

    worker_profession = get_profession_from_file(w.profession_id);
    worker_equipment = get_equipment_from_file(w.equipment_id);

    Product produced_product;
    produced_product = get_product_from_file(worker_equipment.product_id);

    w.salary = (1+w.experience/100.0)*worker_profession.basic_rate;
    w.salary+=0.02*(w.products_per_month)*(produced_product.selling_price-produced_product.cost_price);

    printf("Salary of a worker with id %d = %.f \n",w.id, w.salary);

}

/* Input director
input director from file
@param - id of the director to get
@result �  Director object
*/
Director get_director_from_file(int director_id){
    Director p;

    FILE* fp = fopen("../directors.csv", "r");

    if (!fp)
        printf("Can't open file\n");

    else {
        char line[200];

        int row = 0;
        int column = 0;

        while (fgets(line,200,fp)) {
            column = 0;
            row++;

            if (row == 1)
                continue;

            char* value = strtok(line, ",");

            while (value) {
                int current_id;
                if (column==0){
                    current_id = atoi(value);
                }
                if (current_id==director_id){
                    if (column == 0) {
                        p.id = atoi(value);
                    }
                    else if (column == 1) {
                        strncpy(p.surname,value,50);
                    }
                    else if (column == 2) {
                        p.experience = atoi(value);
                    }
                    else if (column == 3) {
                        p.profession_id = atoi(value);
                    }
                }
                value = strtok(NULL, ",");
                column++;
            }
        }
        fclose(fp);
    }
    return p;
}

/* Output director
output director to file
@param - void
@result �  Director object
*/
void add_director_to_file(Director p){
    FILE* fp = fopen("../directors.csv", "a+");

    if (!fp) {
        printf("Can't open file\n");
    }

    fprintf(fp, "%d,%s,%d,%d\n", p.id, p.surname, p.experience,
            p.profession_id);
    fclose(fp);
}

/* Input director
input director from console
@param - void
@result �  Director object
*/
Director get_director_from_console(){
    Director p;

    char buffer[50];
    char*b = buffer;

    char filename[] = "../directors.csv";
    p.id = set_id(filename);
    printf("Input director surname: ");
    scanf("%[^\n]%*c", p.surname);
    printf("Input director experience in years: ");
    scanf("%d", &p.experience);
    printf("Input profession ID of this director: ");
    scanf("%d", &p.profession_id);

    return p;
}

/* Output director
output director to console
@param - void
@result �  void
*/
void print_director_to_console(Director p){
    printf("Director id: %d \n", p.id);
    printf("Director surname: %s \n", p.surname);
    printf("Director experience: %d\n", p.experience);
    printf("Profession ID of this director: %d\n", p.profession_id);
}

/* Calculate director salary
based on experience and
profession basic rate
@param - Director object
@result �  void
*/
void calculate_director_salary(Director d){
    Profession director_profession;
    director_profession = get_profession_from_file(d.profession_id);

    d.salary = (1+d.experience/5.0)*director_profession.basic_rate;

    printf("Salary of a director with id %d = %.f \n",d.id, d.salary);
}

/* Input sideworker
input sideworker from file
@param - id of the sideworker to get
@result �  SideWorker object
*/
SideWorker get_sideworker_from_file(int sideworker_id){
    SideWorker p;

    FILE* fp = fopen("../sideworkers.csv", "r");

    if (!fp)
        printf("Can't open file\n");

    else {
        char line[230];

        int row = 0;
        int column = 0;

        while (fgets(line,230,fp)) {
            column = 0;
            row++;

            if (row == 1)
                continue;

            char* value = strtok(line, ",");

            while (value) {
                int current_id;
                if (column==0){
                    current_id = atoi(value);
                }

                if (current_id==sideworker_id){
                    if (column == 0) {
                        p.id = atoi(value);
                    }
                    else if (column == 1) {
                        strncpy(p.surname,value,50);
                    }
                    else if (column == 2) {
                        p.experience = atoi(value);
                    }
                    else if (column == 3) {
                        p.products_per_month = atoi(value);
                    }
                    else if (column == 4) {
                        p.equipment_id = atoi(value);
                    }
                    else if (column == 5) {
                        p.profession_id = atoi(value);
                    }
                    else if (column == 6) {
                        p.director_id = atoi(value);
                    }
                    else if (column == 7) {
                        strncpy(p.side_work_type,value,50);
                    }
                }

                value = strtok(NULL, ",");
                column++;
            }
        }

        fclose(fp);
    }

    return p;
}

/* Output sideworker
output sideworker to file
@param - SideWorker object
@result �  void
*/
void add_sideworker_to_file(SideWorker p){
    FILE* fp = fopen("../sideworkers.csv", "a+");

    if (!fp) {
        printf("Can't open file\n");
    }

    fprintf(fp, "%d,%s,%d,%d,%d,%d,%d,%s\n", p.id,p.surname, p.experience,
            p.products_per_month, p.equipment_id, p.profession_id,
            p.director_id,p.side_work_type);
    fclose(fp);
}

/* Input sideworker
input sideworker from console
@param - void
@result �  SideWorker object
*/
SideWorker get_sideworker_from_console(){
    SideWorker p;

    char buffer[50];
    char*b = buffer;

    char filename[] = "../sideworkers.csv";
    p.id = set_id(filename);
    printf("Input sideworker surname: ");
    scanf("%[^\n]%*c", p.surname);
    printf("Input sideworker experience in years: ");
    scanf("%d", &p.experience);
    printf("Input number of products produced per month: ");
    scanf("%d", &p.products_per_month);
    printf("Input equipment ID used by sideworker: ");
    scanf("%d", &p.equipment_id);
    printf("Input profession ID of this sideworker: ");
    scanf("%d", &p.profession_id);
    printf("Input director ID of this sideworker: ");
    scanf("%d", &p.director_id);
    printf("Input side work type: ");
    getchar();
    scanf("%[^\n]%*c", p.side_work_type);

    return p;
}

/* Output sideworker
output sideworker to console
@param - SideWorker object
@result �  void
*/
void print_sideworker_to_console(SideWorker p){
    printf("SideWorker id: %d \n", p.id);
    printf("SideWorker surname: %s \n", p.surname);
    printf("SideWorker experience: %d\n", p.experience);
    printf("Number of products produced per month: %d\n", p.products_per_month);
    printf("Equipment ID used by worker: %d\n", p.equipment_id);
    printf("Profession ID of this worker: %d\n", p.profession_id);
    printf("Director ID of this worker:: %d\n", p.director_id);
    printf("Side work type: %s \n", p.side_work_type);
}

/* Calculate sideworker salary
based on experience,
profession basic rate, and
number of produced products
@param - SideWorker object
@result �  void
*/
void calculate_sideworker_salary(SideWorker w){
    Profession worker_profession;
    Equipment worker_equipment;

    worker_profession = get_profession_from_file(w.profession_id);
    worker_equipment = get_equipment_from_file(w.equipment_id);

    Product produced_product;
    produced_product = get_product_from_file(worker_equipment.product_id);

    w.salary = (1+w.experience/100.0)*worker_profession.basic_rate;
    w.salary+=0.02*(w.products_per_month)*(produced_product.selling_price-produced_product.cost_price);


    printf("Salary of a sideworker with id %d = %.f \n",w.id, w.salary);
}
