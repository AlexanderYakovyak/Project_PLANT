/* File PLANT.h
Realization of structures for task "PLant": Product, Equipment
Profession, Worker, Director
Done by Yakoviak Alexander (2.2 comp.math group)
Date 16.11.2021
Headers for structures: Product, Equipment,
Profession, abstract class Human, Worker, Director
*/

#ifndef PLANT_H_
#define PLANT_H_

/*defining the maximum length for sequence of chars in C*/
#define L 50

/*function to automatically set an id for new object
of any class for writing to the file*/
int set_id(char filename[L]);

/* Default structure of Product */
struct Product {
    int id;
    char name[L];
    float cost_price;
    float selling_price;
};

struct Product;

/* function for product input from file*/
Product get_product_from_file(int product_id);

/* function for product output to file*/
void add_product_to_file(Product p);

/* function for product input from console*/
Product get_product_from_console();

/* function for product output to console*/
void print_product_to_console(Product p);

/* Default structure of Equipment */
struct Equipment {
    int id;
    char name[L];
    float price;
    int product_id;
};

struct Equipment;

/* function for equipment input from file*/
Equipment get_equipment_from_file(int equipment_id);

/* function for equipment output to file*/
void add_equipment_to_file(Equipment e);

/* function for equipment input from console*/
Equipment get_equipment_from_console();

/* function for equipment output to console*/
void print_equipment_to_console(Equipment e);

/* Default structure of Profession */
struct Profession {
    int id;
    char name[L];
    float basic_rate;
};

struct Profession;

/* function for profession input from file*/
Profession get_profession_from_file(int profession_id);

/* function for profession output to file*/
void add_profession_to_file(Profession prof);

/* function for profession input from console*/
Profession get_profession_from_console();

/* function for profession output to console*/
void print_profession_to_console(Profession prof);

/* Default structure of Worker */
struct Worker {
    int id;
    char surname[L];
    int experience;
    int products_per_month;
    int equipment_id;
    int profession_id;
    int director_id;
    float salary;
};

struct Worker;

/* function for worker input from file*/
Worker get_worker_from_file(int worker_id);

/* function for worker output to file*/
void add_worker_to_file(Worker w);

/* function for worker input from console*/
Worker get_worker_from_console();

/* function for worker output to console*/
void print_worker_to_console(Worker w);

/* function to calculate worker's salary*/
void calculate_worker_salary(Worker w);

/* Default structure of Director */
struct Director {
    int id;
    char surname[L];
    int experience;
    int profession_id;
    float salary;
};

struct Director;

/* function for director input from file*/
Director get_director_from_file(int director_id);

/* function for director output to file*/
void add_director_to_file(Director d);

/* function for director input from console*/
Director get_director_from_console();

/* function for director output to console*/
void print_director_to_console(Director d);

/* function to calculate director's salary*/
void calculate_director_salary(Director d);

/* Default structure of SideWorker */
struct SideWorker {
    int id;
    char surname[L];
    int experience;
    int products_per_month;
    int equipment_id;
    int profession_id;
    int director_id;
    char side_work_type[L];
    float salary;
};

struct SideWorker;

/* function for sideworker input from file*/
SideWorker get_sideworker_from_file(int sideworker_id);

/* function for sideworker output to file*/
void add_sideworker_to_file(SideWorker w);

/* function for sideworker input from console*/
SideWorker get_sideworker_from_console();

/* function for sideworker output to console*/
void print_sideworker_to_console(SideWorker w);

/* function to calculate sideworker's salary*/
void calculate_sideworker_salary(SideWorker w);

#endif // PLANT_H_
