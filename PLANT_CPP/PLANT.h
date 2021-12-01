/* File PLANT.h
Realization of classes for task "PLant": Product, Equipment
Profession, abstract class Human, Worker, Director, Side Worker
Done by Yakoviak Alexander (2.2 comp.math group)
Date 16.11.2021
Headers for classes: Product, Equipment,
Profession, abstract class Human, Worker, Director, Side Worker
*/
#include <string>
#ifndef PLANT_H_
#define PLANT_H_

#ifdef __cplusplus
extern "C"{
#endif
#include "../PLANT_C/PLANT.h"
#ifdef __cplusplus
} // end extern "C"
#endif


using namespace std;

/*function to automatically set an id for new object
of any class for writing to the file*/
int set_id(string filename);

/* Default class of Product */
class Product {
public:
    int id;
    string name;
    float cost_price;
    float selling_price;

    /*Different types of constructors*/
    Product ();
    Product (int id, string name, float cost_price, float selling_price);
    Product (const Product &p);

    /* method for product input from file*/
    void get_from_file(int product_id);

    /* method for product output to file*/
    void add_to_file();

    /* method for product input from console*/
    void print_to_console();

    /* method for product output to console*/
    void get_from_console();
};

/* Default class of Equipment */
class Equipment {
public:
    int id;
    string name;
    float price;
    int product_id;

    /*Different types of constructors*/
    Equipment();
    Equipment (int id, string name, float price, int product_id);
    Equipment(const Equipment &e);

    /* method for equipment input from file*/
    void get_from_file(int equipment_id);

    /* method for equipment output to file*/
    void add_to_file();

    /* method for equipment input from console*/
    void print_to_console();

    /* method for equipment output to console*/
    void get_from_console();

};

/* Default class of Profession */
class Profession {
public:
    int id;
    string name;
    float basic_rate;

    /*Different types of constructors*/
    Profession();
    Profession(int id, string name, float basic_rate);
    Profession(const Profession &p);

    /* method for profession input from file*/
    void get_from_file(int profession_id);

    /* method for profession output to file*/
    void add_to_file();

    /* method for profession input from console*/
    void print_to_console();

    /* method for profession output to console*/
    void get_from_console();

};

/* Base class of Human */
class Human {
public:

    virtual void get_from_console() = 0;
    virtual void print_to_console() = 0;

};

/* Derived and base class of Worker */
class Worker : public Human {
public:
    int id;
    string surname;
    int experience;
    int products_per_month;
    int equipment_id;
    int profession_id;
    int director_id;
    float salary;

    /*Different types of constructors*/
    Worker(int id,string surname,int experience, int products_per_month, int equipment_id,int profession_id,int director_id);
    Worker ();
    Worker (const Worker &w);

    /* method for calculating salary of worker*/
    void calculate_salary();

    /* method for worker input from file*/
    void get_from_file(int worker_id);

    /* method for worker output to file*/
    void add_to_file();

    /* method for worker input from console*/
    virtual void get_from_console();

    /* method for worker output to console*/
    virtual void print_to_console();
};

/* Derived class of Director */
class Director: public Worker {
public:
    /*Different types of constructors*/
    Director(int id,string surname,int experience,int profession_id);
    Director();
    Director(const Director &d);

    /* method for calculating salary of director*/
    void calculate_salary();

    /* method for director input from file*/
    void get_from_file(int director_id);

    /* method for director output to file*/
    void add_to_file();

    /* method for director input from console*/
    virtual void get_from_console();

    /* method for director output to console*/
    virtual void print_to_console();
};

/* Derived class of Sideworker */
class SideWorker : public Worker {
public:
    string side_work_type;

    /*Different types of constructors*/
    SideWorker(int id,string surname,int experience, int products_per_month, int equipment_id,int profession_id,int director_id,string side_work_type);
    SideWorker();
    SideWorker(const SideWorker &sw);

    /* method for calculating salary of side_worker*/
    void calculate_salary();

    /* method for side worker input from file*/
    void get_from_file(int side_worker_id);

    /* method for side worker output to file*/
    void add_to_file();

    /* method for side worker input from console*/
    virtual void get_from_console();

    /* method for side worker output to console*/
    virtual void print_to_console();
};

#endif // PLANT_H_

