/* File PLANT.cpp
Realization of functions for task "Plant"
Done by Yakoviak Alexander (2.2 comp.math group)
Date 16.11.2021
Implementations of classes: Product, Equipment,
Profession, abstract class Human, Worker, Director, Side Worker
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <vector>

#include "PLANT.h"
using namespace std;

/*function to automatically set an id for new object
of any class for writing to the file*/
int set_id(string filename){
    int id=-1;
    string line;
    ifstream fin(filename);

    while(fin.good()){
        getline(fin,line);
        id++;
        if(fin.fail()){
            break;
        }
    }

    return id;
}

/*Constructor for Product object with all given information*/
Product::Product(int id, string name, float cost_price, float selling_price){
    this->id=id;
    this->name=name;
    this->cost_price=cost_price;
    this->selling_price=selling_price;
}

/*Empty Constructor for Product object*/
Product::Product(){}

/*Constructor to copy Product object*/
Product::Product(const Product &p):Product(p.id,p.name,p.cost_price,p.selling_price){}

/* Input product
input product from file
@param - id of the product to get
@result �  void
*/
void Product::get_from_file(int product_id){
    ifstream fin("../products.csv");

    vector<string> row;
    string line;
    int roll2=0, count = 0;

    while (fin.good()) {
        row.clear();
        getline(fin, line);

        if(fin.fail()){
            break;
        }

        stringstream ss(line);

        while (ss.good()) {
            string substr;
            getline(ss, substr, ',');
            row.push_back(substr);
        }

        if (row[0]=="Product ID"){
            continue;
        }else if (stoi(row[0])==product_id){
            count=1;
            id = product_id;
            name = row[1];
            cost_price = stof(row[2]);
            selling_price = stof(row[3]);
            break;
        }
    }

    if (count == 0)
        cout << "Product with such id not found\n";

    fin.close();

}

/* Output product
output product to file
@param - void
@result �  void
*/
void Product::add_to_file(){
    ofstream  fout;

    fout.open("../products.csv", std::ios_base::app);

    fout << id << ", "
         << name << ", "
         << cost_price << ", "
         << selling_price << ", "
         << "\n";

    fout.close();
}

/* Input product
input product from console
@param - void
@result �  void
*/
void Product::get_from_console(){
    id = set_id("../products.csv");
    cout<<"Input product name: ";
    getline(cin,name);
    cout<<"Input product cost price: ";
    cin>>cost_price;
    cout<<"Input product selling price: ";
    cin>>selling_price;
}

/* Output product
output product to console
@param - void
@result �  void
*/
void Product::print_to_console(){
    cout<<"Product name: "<<name<<endl;
    cout<<"Cost price: "<<cost_price<<endl;
    cout<<"Selling price: "<<selling_price<<endl;
}

/*Constructor for Equipment object with all given information*/
Equipment::Equipment(int id, string name, float price, int product_id){
    this->id=id;
    this->name=name;
    this->price=price;
    this->product_id=product_id;
}

/*Empty Constructor for Equipment object*/
Equipment::Equipment(){}

/*Constructor to copy Equipment object*/
Equipment::Equipment(const Equipment &e):Equipment(e.id,e.name,e.price,e.product_id){}

/* Input equipment
input equipment from file
@param - id of the equipment to get
@result �  void
*/
void Equipment::get_from_file(int equipment_id){
    ifstream fin("../equipments.csv");

    vector<string> row;
    string line;
    int roll2=0, count = 0;

    while (fin.good()) {
        row.clear();
        getline(fin, line);

        if(fin.fail()){
            break;
        }

        stringstream ss(line);

        while (ss.good()) {
            string substr;
            getline(ss, substr, ',');
            row.push_back(substr);
        }

        if (row[0]=="Equipment ID"){
            continue;
        }else if (stoi(row[0])==equipment_id){
            count=1;
            id = equipment_id;
            name = row[1];
            price = stof(row[2]);
            product_id = stoi(row[3]);
            break;
        }
    }

    if (count == 0)
        cout << "Equipment with such id not found\n";

    fin.close();
}

/* Output equipment
equipment product to file
@param - void
@result �  void
*/
void Equipment::add_to_file(){
    ofstream  fout;

    fout.open("../equipments.csv", std::ios_base::app);

    fout << id << ", "
         << name << ", "
         << price << ", "
         << product_id << ", "
         << "\n";

    fout.close();
}

/* Input equipment
input equipment from console
@param - void
@result �  void
*/
void Equipment::get_from_console(){
    id = set_id("../equipments.csv");
    cout<<"Input equipment name: ";
    getline(cin,name);
    cout<<"Input equipment price: ";
    cin>>price;
    cout<<"Input product ID made by this equipment: ";
    cin>>product_id;
}

/* Output equipment
output equipment to console
@param - void
@result �  void
*/
void Equipment::print_to_console(){
    cout<<"Equipment name: "<<name<<endl;
    cout<<"Price: "<<price<<endl;
    cout<<"Product ID made with this equipment: "<<product_id<<endl;
}

/*Constructor for Profession object with all given information*/
Profession::Profession(int id, string name, float basic_rate){
    this->id=id;
    this->name=name;
    this->basic_rate=basic_rate;
}

/*Empty constructor for Profession object*/
Profession::Profession(){}

/*Constructor to copy Profession object*/
Profession::Profession(const Profession &p):Profession(p.id,p.name,p.basic_rate){}

/* Input profession
input profession from file
@param - id of the profession to get
@result �  void
*/
void Profession::get_from_file(int profession_id){
    ifstream fin("../professions.csv");

    vector<string> row;
    string line;
    int roll2=0, count = 0;

    while (fin.good()) {
        row.clear();
        getline(fin, line);

        if(fin.fail()){
            break;
        }

        stringstream ss(line);

        while (ss.good()) {
            string substr;
            getline(ss, substr, ',');
            row.push_back(substr);
        }

        if (row[0]=="Profession ID"){
            continue;
        }else if (stoi(row[0])==profession_id){
            count=1;
            id = profession_id;
            name = row[1];
            basic_rate = stof(row[2]);
            break;
        }
    }

    if (count == 0)
        cout << "Profession with such id not found\n";

    fin.close();
}

/* Output profession
equipment profession to file
@param - void
@result �  void
*/
void Profession::add_to_file(){
    ofstream  fout;

    fout.open("../professions.csv", std::ios_base::app);

    fout << id << ", "
         << name << ", "
         << basic_rate << ", "
         << "\n";

    fout.close();
}

/* Input profession
input profession from console
@param - void
@result �  void
*/
void Profession::get_from_console(){
    id = set_id("../professions.csv");
    cout<<"Input profession name: ";
    getline(cin,name);
    cout<<"Input profession basic rate: ";
    cin>>basic_rate;
}

/* Output profession
output profession to console
@param - void
@result �  void
*/
void Profession::print_to_console(){
    cout<<"Profession name: "<<name<<endl;
    cout<<"Basic rate: "<<basic_rate<<endl;
}

/*Constructor for Worker object with all given information*/
Worker::Worker(int id,string surname,int experience, int products_per_month, int equipment_id,int profession_id,int director_id){
    this->id=id;
    this->surname=surname;
    this->experience=experience;
    this->products_per_month=products_per_month;
    this->equipment_id=equipment_id;
    this->profession_id=profession_id;
    this->director_id=director_id;
}

/*Empty constructor for Worker object*/
Worker::Worker(){}

/*Constructor to copy Worker object*/
Worker::Worker(const Worker &w):Worker(w.id,w.surname,w.experience,w.products_per_month,w.equipment_id,w.profession_id,w.director_id){}

/* Input worker
input worker from file
@param - id of the worker to get
@result �  void
*/
void Worker::get_from_file(int worker_id){
    ifstream fin("../workers.csv");

    vector<string> row;
    string line;
    int roll2=0, count = 0;

    while (fin.good()) {
        row.clear();
        getline(fin, line);

        if(fin.fail()){
            break;
        }

        stringstream ss(line);

        while (ss.good()) {
            string substr;
            getline(ss, substr, ',');
            row.push_back(substr);
        }

        if (row[0]=="Worker ID"){
            continue;
        }else if (stoi(row[0])==worker_id){
            count=1;
            id = worker_id;
            surname = row[1];
            experience = stoi(row[2]);
            products_per_month = stoi(row[3]);
            equipment_id = stoi(row[4]);
            profession_id = stoi(row[5]);
            director_id=stoi(row[6]);
            break;
        }
    }

    if (count == 0)
        cout << "Worker with such id not found\n";

    fin.close();
}

/* Output worker
equipment worker to file
@param - void
@result �  void
*/
void Worker::add_to_file(){
    ofstream  fout;

    fout.open("../workers.csv", std::ios_base::app);

    fout << id << ", "
         << surname << ", "
         << experience << ", "
         << products_per_month << ", "
         << equipment_id << ", "
         << profession_id << ", "
         << director_id << ", "
         << "\n";

    fout.close();
}

/* Input worker
input worker from console
@param - void
@result �  void
*/
void Worker::get_from_console(){
    id = set_id("../workers.csv");
    cout<<"Input worker surname: ";
    cin>>surname;
    cout<<"Input worker experience in years: ";
    cin>>experience;
    cout<<"Input number of products produced per month: ";
    cin>>products_per_month;
    cout<<"Input equipment ID used by worker: ";
    cin>>equipment_id;
    cout<<"Input profession ID of this worker: ";
    cin>>profession_id;
    cout<<"Input director ID of this worker: ";
    cin>>director_id;
}

/* Calculate salary
calculate salary of a worker
@param - void
@result �  void
*/
void Worker::calculate_salary(){
    Profession worker_profession;
    Equipment worker_equipment;

    worker_profession.get_from_file(profession_id);
    worker_equipment.get_from_file(equipment_id);

    Product produced_product;
    produced_product.get_from_file(worker_equipment.product_id);

    salary = (1+experience/100.0)*worker_profession.basic_rate;
    salary+=0.02*(products_per_month)*(produced_product.selling_price-produced_product.cost_price);

    cout<<"Salary of a worker with id "<<id<<" = "<<salary<<endl;
}

/* Output worker
output worker to console
@param - void
@result �  void
*/
void Worker::print_to_console(){
    cout<<"Surname:"<<surname<<endl;
    cout<<"Experience in years: "<<experience<<endl;
    cout<<"Products produced per month: "<<products_per_month<<endl;
    cout<<"Director ID: "<<director_id<<endl;
}

/*Constructor for Director object with all given information*/
Director::Director(int id,string surname,int experience,int profession_id){
    this->id=id;
    this->surname=surname;
    this->experience=experience;
    this->profession_id=profession_id;
}

/*Empty constructor for Director object*/
Director::Director(){}

/*Constructor to copy Director object*/
Director::Director(const Director &d):Director(d.id,d.surname,d.experience,d.profession_id){}

/* Input director
input director from file
@param - id of the director to get
@result �  void
*/
void Director::get_from_file(int director_id){
    ifstream fin("../directors.csv");

    vector<string> row;
    string line;
    int roll2=0, count = 0;

    while (fin.good()) {
        row.clear();
        getline(fin, line);

        if(fin.fail()){
            break;
        }

        stringstream ss(line);

        while (ss.good()) {
            string substr;
            getline(ss, substr, ',');
            row.push_back(substr);
        }

        if (row[0]=="Director ID"){
            continue;
        }else if (stoi(row[0])==director_id){
            count=1;
            id = director_id;
            surname = row[1];
            experience = stoi(row[2]);
            profession_id = stoi(row[3]);
            break;
        }
    }

    if (count == 0)
        cout << "Director with such id not found\n";

    fin.close();
}

/* Output director
equipment director to file
@param - void
@result �  void
*/
void Director::add_to_file(){
    ofstream  fout;

    fout.open("../directors.csv", std::ios_base::app);

    fout << id << ", "
         << surname << ", "
         << experience << ", "
         << profession_id << ", "
         << "\n";

    fout.close();
}

/* Input director
input director from console
@param - void
@result �  void
*/
void Director::get_from_console(){
    id = set_id("../directors.csv");
    cout<<"Input director surname: ";
    cin>>surname;
    cout<<"Input director experience in years: ";
    cin>>experience;
    cout<<"Input profession ID of this director: ";
    cin>>profession_id;
}

/* Output director
output director to console
@param - void
@result �  void
*/
void Director::print_to_console(){
    cout<<"Surname:"<<surname<<endl;
    cout<<"Experience in years: "<<experience<<endl;
}

/* Calculate salary
calculate salary of a director
@param - void
@result �  void
*/
void Director::calculate_salary(){
    Profession director_profession;

    director_profession.get_from_file(profession_id);

    salary = (1+experience/5.0)*director_profession.basic_rate;

    cout<<"Salary of a director with id "<<id<<" = "<<salary<<endl;
}

/*Constructor for SideWorker object with all given information*/
SideWorker::SideWorker(int id,string surname,int experience, int products_per_month, int equipment_id,int profession_id,int director_id,string side_work_type)
:Worker(id,surname,experience,products_per_month,equipment_id,profession_id,director_id)
{
    this->side_work_type=side_work_type;
}

/*Empty constructor for SideWorker object*/
SideWorker::SideWorker(){}

/*Constructor to copy SideWorker object*/
SideWorker::SideWorker(const SideWorker &sw):SideWorker(sw.id,sw.surname,sw.experience,sw.products_per_month,sw.equipment_id,sw.profession_id,sw.director_id,sw.side_work_type){}

/* Input sideworker
input sideworker from file
@param - id of the director to get
@result �  void
*/
void SideWorker::get_from_file(int side_worker_id){
    ifstream fin("../sideworkers.csv");

    vector<string> row;
    string line;
    int roll2=0, count = 0;

    while (fin.good()) {
        row.clear();
        getline(fin, line);

        if(fin.fail()){
            break;
        }

        stringstream ss(line);

        while (ss.good()) {
            string substr;
            getline(ss, substr, ',');
            row.push_back(substr);
        }

        if (row[0]=="SideWorker ID"){
            continue;
        }else if (stoi(row[0])==side_worker_id){
            count=1;
            id = side_worker_id;
            surname = row[1];
            experience = stoi(row[2]);
            products_per_month = stoi(row[3]);
            equipment_id = stoi(row[4]);
            profession_id = stoi(row[5]);
            director_id=stoi(row[6]);
            side_work_type=row[7];
            break;
        }
    }

    if (count == 0)
        cout << "SideWorker with such id not found\n";

    fin.close();
}

/* Output sideworker
equipment sideworker to file
@param - void
@result �  void
*/
void SideWorker::add_to_file(){
    ofstream  fout;

    fout.open("../sideworkers.csv", std::ios_base::app);

    fout << id << ", "
         << surname << ", "
         << experience << ", "
         << products_per_month << ", "
         << equipment_id << ", "
         << profession_id << ", "
         << director_id << ", "
         << side_work_type << ", "
         << "\n";

    fout.close();
}

/* Input sideworker
input sideworker from console
@param - void
@result �  void
*/
void SideWorker::get_from_console(){
    id = set_id("../sideworkers.csv");
    cout<<"Input worker surname: ";
    cin>>surname;
    cout<<"Input worker experience in years: ";
    cin>>experience;
    cout<<"Input products produced per month: ";
    cin>>products_per_month;
    cout<<"Input equipment ID used by worker: ";
    cin>>equipment_id;
    cout<<"Input profession ID of this worker: ";
    cin>>profession_id;
    cout<<"Input director ID of this worker: ";
    cin>>director_id;
    cout<<"Input side work type of this worker: ";
    getchar();
    getline(cin,side_work_type);
}

/* Output sideworker
output sideworker to console
@param - void
@result �  void
*/
void SideWorker::print_to_console(){
    cout<<"Surname:"<<surname<<endl;
    cout<<"Experience in years: "<<experience<<endl;
    cout<<"Products produced per month: "<<products_per_month<<endl;
    cout<<"Director ID: "<<director_id<<endl;
    cout<<"Side work type:"<<side_work_type<<endl;
}

/* Calculate salary
calculate salary of a sideworker
@param - void
@result �  void
*/
void SideWorker::calculate_salary(){
    Profession worker_profession;
    Equipment worker_equipment;

    worker_profession.get_from_file(profession_id);
    worker_equipment.get_from_file(equipment_id);

    Product produced_product;
    produced_product.get_from_file(worker_equipment.product_id);

    salary = (1+experience/100.0)*worker_profession.basic_rate;
    salary+=0.02*(products_per_month)*(produced_product.selling_price-produced_product.cost_price);

    cout<<"Salary of a side worker with id "<<id<<" = "<<salary<<endl;
}

