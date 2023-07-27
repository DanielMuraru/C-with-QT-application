#pragma once
#include <QtWidgets/QApplication>
#include "Observer.h"
//#include <QtWidgets/qmainwindow.h>
#include <qboxlayout.h>
#include <qtableview.h>
#include <qabstractitemview.h>
#include <QWidget>
#include <qlabel.h>
#include <QLabel>
#include <qwidget.h>
#include <qpushbutton.h>
#include <qradiobutton.h>
#include <qformlayout.h>
#include <qgroupbox.h>
#include <qlineedit.h>
#include <qtablewidget.h>
#include <qlistwidget.h>
#include <qheaderview.h>
#include <qmessagebox.h>
#include <qevent.h>
#include <qpainter.h>
#include <qspinbox.h>
#include <random>
#include "service.h"
#include "TableModel.h"
//class gui;
class Wishlist_window;

class Products_table :public QTableView,public Observable
{
	friend class gui;
	friend class Wishlist_window;
private:
	Service& s;
	Wishlist_window* wnd;

public:
	Products_table(Service& g, Wishlist_window* w);
	void mouseDoubleClickEvent(QMouseEvent* event)override;
	//void dataChanged(const QModelIndex& topLeft, const QModelIndex& bottomRight, const QList<int>& roles = QList<int>());
};
class Products_table_list :public QListWidget, public Observable
{
	friend class gui;
	friend class Wishlist_window;
private:
	Service& s;
	Wishlist_window* wnd;

public:
	Products_table_list(Service& g, Wishlist_window* w);
	void mouseDoubleClickEvent(QMouseEvent* event)override;

};
class gui:public QWidget
{
	friend class Filter_window;
	friend class Wishlist_window;
	friend class Products_table;
	friend class CrudCart_Window;
	friend class ReadOnly_cart;
	friend class QTableView;
private:
	Service& service;
	QHBoxLayout* app_layout;
	QVBoxLayout* app_left_layout;
	QVBoxLayout* app_center_layout;
	QVBoxLayout* app_right_layout;
	QVBoxLayout* app_rightx2_layout;

	QFormLayout* add_layout;
	QPushButton* add_button;
	QLineEdit* name;
	QLineEdit* type;
	QLineEdit* price;
	QLineEdit* manufacturer;

	QFormLayout* delete_layout;
	QPushButton* delete_button;
	QLineEdit* position;

	QFormLayout* find_layout;
	QPushButton* find_button;
	QLineEdit* find_text;

	QFormLayout* modify_layout;
	QPushButton* modify_button;
	QLineEdit* modify_text;
	QLineEdit* modify_text_manufacturer;
	QLineEdit* modify_text_price;

	Products_table* products;
	table_model* mod;
	Products_table_list* products_list;

	QVBoxLayout* sort_layout;
	QVBoxLayout* by_layout;
	QVBoxLayout* order_layout;
	QRadioButton* name_sort;
	QRadioButton* price_sort;
	QRadioButton* name_and_type;
	QRadioButton* ascending_sort;
	QRadioButton* descending_sort;
	QPushButton* sort_button;


	QVBoxLayout* filter_layout;
	QGroupBox* filter_box;
	QRadioButton* name_radio_button;
	QRadioButton* price_filter;
	QRadioButton* manufacturer_filter;
	QPushButton* filter_window_button;


	QPushButton* cos;
	Wishlist_window* wnd_wishlist;

	CrudCart_Window* crud_cart;
	QPushButton* crudcart_button;
	QPushButton* readonlycart_button;

	ReadOnly_cart* read_cart;

	QPushButton* undo;

	QPushButton* reload_button;

	QWidget* lab_widget;
	QVBoxLayout* layout_lab;

	void initialize();
	void connections();
	void reload_data(std::vector<Produs>&);
	void reload_buttons();

public:
	gui(Service& s) :service(s) { initialize(); connections(); try { reload_data(service.get_all_service()); } catch (RepoExceptions&) {} reload_buttons(); }
	
	void add_product_gui();
	void keyPressEvent(QKeyEvent* e) override
	{
		if (e->keyCombination() == QKeyCombination(Qt::ControlModifier, Qt::Key_Z))
		{
			undo->click();
		}
	}
	

};
class Filter_window:public QWidget
{	
	friend class gui;
private:
	const gui& g;
	QTableWidget* products_filtered;
	QVBoxLayout* main_layout = new QVBoxLayout;
	QFormLayout* layout_filter_new_window = new QFormLayout;
	QWidget* form_for_filter = new QWidget;
	QLineEdit* name_filter = new QLineEdit;
	QLabel* name_filter_label = new QLabel(QString::fromStdString("First letter of the name"));
	QLineEdit* price_filter = new QLineEdit;
	QLabel* price_filter_label = new QLabel(QString::fromStdString("Price"));
	QLineEdit* manufacturer_filter = new QLineEdit;
	QLabel* manufacturer_filter_label = new QLabel(QString::fromStdString("First letter of the manufacturer"));
	std::string filtru;
	QString filter;
public:
	Filter_window(gui& gs, std::string s);
	void keyPressEvent(QKeyEvent* e)override;
	
	
	

};
class Wishlist_window :public QWidget,public Observer,public Observable
{
	//Cu sablonul observer
	//In timp ce fereastra pentru cos este deschisa,daca se da dublu click pe un produs din lista de produse acesta va fi adaugat in cos
	friend class gui;
	friend class CrudCart_Window;
	friend class ReadOnly_cart;
private:
	 gui& pr;
	//Cos& cos;
	QHBoxLayout* main_layout = new QHBoxLayout;
	QVBoxLayout* right_layout = new QVBoxLayout;
	QWidget* right = new QWidget;
	QPushButton* generate = new QPushButton(QString::fromStdString("Generate a cart"));
	QSpinBox* number_of_products_to_generate = new QSpinBox;
	QHBoxLayout* layout_slider = new QHBoxLayout;
	QLabel* label_slider = new QLabel(QString::number(0));
	QSlider* number = new QSlider(Qt::Horizontal);
	
	QFormLayout* layout_save_wishlist = new QFormLayout;
	QPushButton* save = new QPushButton("Save cart");
	QLabel* label_path = new QLabel(QString::fromStdString("Path"));
	QLineEdit* path = new QLineEdit;

	QPushButton* empty = new QPushButton(QString::fromStdString("Empty cart"));

	QWidget* left = new QWidget;
	QFormLayout* main_layout_wishlist = new QFormLayout;
	QLabel* label = new QLabel(QString::fromStdString("List of products in cart"));
	QTableWidget* table = new QTableWidget(1,4);
	void connections();
public:
	Wishlist_window(gui& s,CrudCart_Window*);
	void update() override;

};
class CrudCart_Window:public QWidget,public Observer,public Observable
{	
	friend class gui;
	friend class Wishlist_Window;

private:
	const gui& pr;
	QHBoxLayout* crud_layout;
	QTableWidget* crud_table;

	QHBoxLayout* generate_layout;
	QSpinBox* number_crud;
	QPushButton* empty_crud_button;

	QVBoxLayout* right_crud_layout;
	QPushButton* generate_crud_button;

	void connections_crud();
public:
	CrudCart_Window(const gui& s);
	void update() override;




};
class ReadOnly_cart:public QWidget,public Observable,public Observer
{

	friend class gui;
	friend class Wishlist_Window;
private:
	QHBoxLayout* rdonly_cart_layout;

	Service& serv;
public:
	ReadOnly_cart(Service& serv) :serv(serv) { this->setGeometry(50, 50, 1024, 580); }

	void paintEvent(QPaintEvent* e)   override;

	void update();


	
};