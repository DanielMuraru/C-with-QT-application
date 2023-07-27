#include "GUI.h"


void gui::initialize()
{
	
	app_layout = new QHBoxLayout;
	//this->setStyleSheet("background-image:url(pz.jpg);background-color:rgba(255,255,255,50);color:red; ");
	this->setLayout(app_layout);

	app_left_layout = new QVBoxLayout;
	QWidget* app_left_widget = new QWidget;
	app_left_widget->setLayout(app_left_layout);

	add_layout = new QFormLayout;
	QWidget* app_left_add = new QWidget;
	app_left_add->setLayout(add_layout);
	QLabel* label_name = new QLabel(QString::fromStdString("Name of product"));
	QLabel* label_type = new QLabel(QString::fromStdString("Type of product"));
	QLabel* label_price = new QLabel(QString::fromStdString("Price of product"));
	QLabel* label_manufacturer = new QLabel(QString::fromStdString("Manufacturer of product"));
	
	name = new QLineEdit();
	type = new QLineEdit();
	price = new QLineEdit();
	manufacturer = new QLineEdit();
	add_layout->addRow(label_name, name);
	add_layout->addRow(label_type, type);
	add_layout->addRow(label_price, price);
	add_layout->addRow(label_manufacturer, manufacturer);
	add_button = new QPushButton(QString::fromStdString("Add product"));
	//add_button->setStyleSheet("background-color: lightgrey;border:none;color:black;");
	add_layout->addWidget(add_button);

	
	app_left_layout->addWidget(app_left_add);


	delete_layout = new QFormLayout;
	QWidget* delete_left_widget = new QWidget;
	delete_left_widget->setLayout(delete_layout);
	QLabel* position_label = new QLabel("Select from the list the product you want to delete");
	//position = new QLineEdit;
	delete_layout->addRow(position_label);
	delete_button = new QPushButton(QString::fromStdString("Delete product"));
	delete_layout->addWidget(delete_button);

	app_left_layout->addWidget(delete_left_widget);

	find_layout = new QFormLayout;
	QWidget* find_widget = new QWidget;
	find_widget->setLayout(find_layout);
	QLabel* find_product_label = new QLabel(QString::fromStdString("Name of product"));
	find_text = new QLineEdit;
	find_layout->addRow(find_product_label, find_text);
	find_button = new QPushButton(QString::fromStdString("Find product"));
	find_layout->addWidget(find_button);

	app_left_layout->addWidget(find_widget);


	modify_layout = new QFormLayout;
	QWidget* modify_widget = new QWidget;
	modify_widget->setLayout(modify_layout);
	QLabel* modify_product_label = new QLabel(QString::fromStdString("Select a product from the list and write the new info"));
	QLabel* modify_product_label_manufacturer = new QLabel(QString::fromStdString("New manufacturer"));
	QLabel* modify_product_label_price = new QLabel(QString::fromStdString("New price"));
	//modify_text = new QLineEdit;
	modify_text_manufacturer = new QLineEdit;
	modify_text_price = new QLineEdit;
	modify_layout->addRow(modify_product_label);
	modify_layout->addRow(modify_product_label_manufacturer, modify_text_manufacturer);
	modify_layout->addRow(modify_product_label_price, modify_text_price);
	modify_button = new QPushButton(QString::fromStdString("Modify product"));
	modify_layout->addWidget(modify_button);
	app_left_layout->addWidget(modify_widget);


	app_center_layout = new QVBoxLayout;
	QWidget* app_center_widget = new QWidget;
	app_center_widget->setLayout(app_center_layout);

	sort_layout = new QVBoxLayout;
	QGroupBox* sort_box = new QGroupBox(QString::fromStdString("Sort"));
	sort_box->setLayout(sort_layout);
	QGroupBox* by_box = new QGroupBox(QString::fromStdString("By"));
	QGroupBox* order_box = new QGroupBox(QString::fromStdString("Order"));
	by_layout = new QVBoxLayout;
	order_layout = new QVBoxLayout;
	by_box->setLayout(by_layout);
	order_box->setLayout(order_layout);
	name_sort = new QRadioButton(QString::fromStdString("Name"));
	price_sort = new QRadioButton(QString::fromStdString("Price"));
	name_and_type = new QRadioButton(QString::fromStdString("Name + type"));
	

	ascending_sort = new QRadioButton(QString::fromStdString("Ascending"));
	descending_sort = new QRadioButton(QString::fromStdString("Descending"));
	order_layout->addWidget(ascending_sort);
	order_layout->addWidget(descending_sort);

	sort_button = new QPushButton(QString::fromStdString("Sort"));

	by_layout->addWidget(name_sort);
	by_layout->addWidget(price_sort);
	by_layout->addWidget(name_and_type);
	by_layout->addWidget(sort_button);
	sort_layout->addWidget(order_box);
	sort_layout->addWidget(by_box);/*
	app_center_layout->addWidget(order_box);
	app_center_layout->addWidget(sort_box);*/

	
	app_center_layout->addWidget(sort_box);
	//app_center_layout->addStretch();

	filter_layout = new QVBoxLayout;
	filter_box = new QGroupBox(QString::fromStdString("Filter"));
	filter_box->setLayout(filter_layout);
	name_radio_button = new QRadioButton(QString::fromStdString("by name"));
	price_filter = new QRadioButton(QString::fromStdString("by price"));
	manufacturer_filter= new QRadioButton(QString::fromStdString("by manufacturer"));
	filter_window_button = new QPushButton(QString::fromStdString("Filtered products"));
	filter_layout->addWidget(name_radio_button);
	filter_layout->addWidget(price_filter);
	filter_layout->addWidget(manufacturer_filter);
	filter_layout->addWidget(filter_window_button);

	app_center_layout->addWidget(filter_box);

	cos = new QPushButton(QString::fromStdString("Access cart window"));
	app_center_layout->addWidget(cos);

	undo = new QPushButton("Undo");
	app_center_layout->addWidget(undo);
	app_center_layout->addStretch();






	app_right_layout = new QVBoxLayout;
	QWidget* app_right_widget = new QWidget;
	app_right_widget->setLayout(app_right_layout);

	
	crud_cart = new CrudCart_Window(*this);
	wnd_wishlist = new Wishlist_window(*this,crud_cart);
	crud_cart->addObs(wnd_wishlist);
	read_cart = new ReadOnly_cart(this->service);
	read_cart->addObs(wnd_wishlist);
	wnd_wishlist->addObs(read_cart);
	crud_cart->addObs(read_cart);
	products = new Products_table(this->service,wnd_wishlist);
	mod = new table_model(products,this->service.get_all_service());
	products->setModel(mod);
	products->addObs(crud_cart);
	//products->setRowCount(2);
	//products->setColumnCount(4);
	products->setSelectionBehavior(QAbstractItemView::SelectRows);
	QStringList headerList;
	headerList << "Name" << "Type" << "Price" << "Manufacturer";
	//products->setHorizontalHeaderLabels(headerList);
	products->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	app_right_layout->addWidget(products);

	app_rightx2_layout = new QVBoxLayout;
	QGroupBox* rightx2 = new QGroupBox(QString::fromStdString("List of products"));
	rightx2->setLayout(app_rightx2_layout);


	products_list = new Products_table_list(this->service, wnd_wishlist);
	products_list->setSelectionBehavior(QAbstractItemView::SelectRows);
	products_list->setSizeAdjustPolicy(QAbstractItemView::AdjustToContents);
	app_rightx2_layout->addWidget(products_list);
	products_list->addObs(crud_cart);

	crudcart_button = new QPushButton("Access crud cart window");
	readonlycart_button = new QPushButton("Acces read only cart window");
	app_rightx2_layout->addWidget(crudcart_button);
	app_rightx2_layout->addWidget(readonlycart_button);

	
	app_layout->addWidget(app_left_widget);
	app_layout->addWidget(app_center_widget);
	app_layout->addWidget(app_right_widget);
	app_layout->addWidget(rightx2);


	layout_lab = new QVBoxLayout;
	lab_widget = new QWidget;
	lab_widget->setLayout(layout_lab);
	app_layout->addWidget(lab_widget);

	reload_button = new QPushButton(QString::fromStdString("Reload"));
	app_left_layout->addWidget(reload_button);
	


}

void gui::connections()
{

	QObject::connect(add_button, &QPushButton::clicked, this, &gui::add_product_gui);
	QObject::connect(delete_button, &QPushButton::clicked, this, [&]() {
		try {
			QModelIndexList nr1 = products->selectionModel()->selectedIndexes();
			//int nr1 = products->selectedItems().count();
			QString name_string;
			//if (products->selectedItems().count() > 0 || products_list->selectedItems().count()>0) {
			if (nr1.size() || products_list->selectedItems().count()>0) {
				if (nr1.size() > 0)
				{
					//QList l = products->selectedItems();
					//name_string = l[0]->data(0).toString();
					int row = products->selectionModel()->selectedIndexes().at(0).row();
					auto cel0 = products->model()->index(row, 0);
					name_string = products->model()->data(cel0,0).toString();
				}
				else if (products_list->selectedItems().count() > 0)
				{

					QList l = products_list->selectedItems();
					QList l2 = l[0]->data(0).toString().split(' ');
					name_string = l2[0];
				}
				service.sterge_produs_service(name_string.toStdString());
				reload_data(service.get_all_service());
				reload_buttons();
				QMessageBox::information(this, "Info", QString::fromStdString("Product successfully deleted"));
				
			}
			else {
				QMessageBox::warning(this, "Warning", QString::fromStdString("None selected items"));

			}
			
		}
		catch (RepoExceptions& e) { QMessageBox::warning(this, "Warning", QString::fromStdString(e.getmsg())); }
		});

	QObject::connect(find_button, &QPushButton::clicked, this, [&]() {
		try {
			string name_string = find_text->text().toStdString();
			find_text->clear();
			Produs p = service.cauta_produs_service(name_string);
			QMessageBox::information(this, "Info", QString::fromStdString("Product found"));
		}
		catch (RepoExceptions& e) {
			QMessageBox* msg = new QMessageBox;
			msg->setGeometry(50, 50, 480, 240);
			msg->warning(this, QString::fromStdString("Eroare adaugare"), QString::fromStdString(e.getmsg()));
		}
		});
	QObject::connect(modify_button, &QPushButton::clicked, this, [&]() {
		
		try {
			//if (products->selectedItems().count() > 0)
			if(products->selectionModel()->selectedIndexes().count()>0)
			{
				//QList l = products->selectedItems();
				QModelIndexList l=products->selectionModel()->selectedIndexes();
				int row = l.at(0).row();
				auto cel0 = products->model()->index(row, 0);
				//string name_string = modify_text->text().toStdString();
				//string name_string = l[0]->data(0).toString().toStdString();
				string name_string = products->model()->data(cel0, 0).toString().toStdString();
				int new_price = modify_text_price->text().toInt();
				string manufacturer_string = modify_text_manufacturer->text().toStdString();
				//modify_text->clear();
				modify_text_price->clear();
				modify_text_manufacturer->clear();

				service.modifica_produs_service(name_string, new_price, manufacturer_string);
				reload_data(service.get_all_service());
				QMessageBox::information(this, "Info", QString::fromStdString("Product successfully modified"));
			}
		}
		catch (RepoExceptions& e) {
			QMessageBox* msg = new QMessageBox;
			msg->setGeometry(50, 50, 480, 240);
			msg->warning(this, QString::fromStdString("Eroare adaugare"), QString::fromStdString(e.getmsg()));
		}
		catch (ValidatorExceptions& e) {
			QMessageBox* msg = new QMessageBox;
			msg->setGeometry(50, 50, 480, 240);
			msg->warning(this, QString::fromStdString("Eroare adaugare"), QString::fromStdString(e.getmsg()));
		}

		});
	QObject::connect(sort_button, &QPushButton::clicked, this, [&]() {

		if (name_sort->isChecked() && ascending_sort->isChecked())
			service.sortare_service(service.get_all_service(), "nume", false);
		else if (name_sort->isChecked() && descending_sort->isChecked())
				service.sortare_service(service.get_all_service(), "nume", true);
		if (price_sort->isChecked() && ascending_sort->isChecked())
			service.sortare_service(service.get_all_service(), "pret", false);
		else if (price_sort->isChecked() && descending_sort->isChecked())
				service.sortare_service(service.get_all_service(), "pret", true);
		if (name_and_type->isChecked() && ascending_sort->isChecked())
			service.sortare_service(service.get_all_service(), "nume+tip", false);
		else if (name_and_type->isChecked() && descending_sort->isChecked())
			service.sortare_service(service.get_all_service(), "nume+tip", true);
		reload_data(service.get_all_service());
		
		QMessageBox::information(this, "Info", QString::fromStdString("List of products has been sorted"));

		});

	QObject::connect(filter_window_button, &QPushButton::clicked, this, [&]() {
		try
		{

			//QVBoxLayout* layout_filter_new_window = new QVBoxLayout;


			if (name_radio_button->isChecked())
			{
			//	QLineEdit* name_filter = new QLineEdit;
			//	QLabel* name_filter_label = new QLabel(QString::fromStdString("Name"));/*
			//	wnd_filte->layout_filter_new_window->addRow(name_filter_label, name_filter);*/
				Filter_window* wnd_filter = new Filter_window(*this,"name");
				wnd_filter->show();
				
			}
			else if (price_filter->isChecked())
			{
				Filter_window* wnd_filter = new Filter_window(*this, "price");
				wnd_filter->show();
			}
			else if (manufacturer_filter->isChecked())
			{

				Filter_window* wnd_filter = new Filter_window(*this, "manufacturer");
				wnd_filter->show();
			}
		}
		catch (RepoExceptions&){}
		
		});
	QObject::connect(cos, &QPushButton::clicked, this, [&]() {

		wnd_wishlist->show();
		
		/*if (products->selectedItems().count() > 0)
		{
			QList l = products->selectedItems();

			service.adauga_produs_cos(l[0]->data(0).toString().toStdString());
			Observable::notify();
		}*/
			
		

		});

	QObject::connect(undo, &QPushButton::clicked, this, [&]() {
		try {
			service.undo_service();
			reload_data(service.get_all_service());
			reload_buttons();
			QMessageBox::information(this, "Info", QString::fromStdString("Undo done"));
		}
		catch (RepoExceptions& e) { QMessageBox::warning(this, "Warning", QString::fromStdString(e.getmsg())); }
		
		});

	QObject::connect(crudcart_button, &QPushButton::clicked, this, [&]() {
		crud_cart->show();
		
		
		});
	QObject::connect(readonlycart_button, &QPushButton::clicked, this, [&]() {
		read_cart->show();
		
		});
	QObject::connect(reload_button, &QPushButton::clicked, this, [&]() {

		try {
			reload_data(service.get_all_service());

		}
		catch (RepoExceptions&) { QMessageBox::warning(this, "Eroare", QString::fromStdString("Failed")); }
		});
}
void gui::reload_data(std::vector<Produs>& products_l)
{

	//products->clearContents();
	//products->setRowCount(products_l.size());
	//products->update();
	/*int line = 0;
	for (auto& it : products_l)
	{
		
		products->setItem(line, 0,new QTableWidgetItem(QString::fromStdString(it.get_nume())));
		products->setItem(line, 1,new QTableWidgetItem(QString::fromStdString(it.get_tip())));
		products->setItem(line, 2,new QTableWidgetItem(QString::number(it.get_pret())));
		products->setItem(line, 3,new QTableWidgetItem(QString::fromStdString(it.get_producator())));
		line++;


	}*/
	mod->setpro(service.get_all_service());
	products_list->clear();
	int line = 0;
	for (auto& it : products_l)
	{
		QString l;
		l.append(QString::fromStdString(it.get_nume())+" ");
		l.append(QString::fromStdString(it.get_tip())+" ");
		l.append(QString::number(it.get_pret())+" ");
		l.append(it.get_producator());
		products_list->insertItem(line, new QListWidgetItem(l));
		line++;


	}
}

void gui::add_product_gui()
{
	try {
		string name_string = name->text().toStdString();
		string type_string = type->text().toStdString();
		int price_string = price->text().toInt();
		string manufacturer_string = manufacturer->text().toStdString();

		name->clear();
		type->clear();
		price->clear();
		manufacturer->clear();
		service.adauga_produs_service(name_string, type_string, price_string, manufacturer_string);
	
		reload_data(service.get_all_service());
		
		QMessageBox::information(this, "Info", QString::fromStdString("Product added in the list"));
		reload_buttons();
	}
	catch (RepoExceptions& e) {
		QMessageBox* msg=new QMessageBox;
		msg->setGeometry(50, 50, 480, 240);
		msg->warning(this, QString::fromStdString("Eroare adaugare"), QString::fromStdString(e.getmsg()));
	}
	catch (ValidatorExceptions& e) {
		QMessageBox* msg = new QMessageBox;
		msg->setGeometry(50, 50, 480, 240);
		msg->warning(this, QString::fromStdString("Eroare adaugare"), QString::fromStdString(e.getmsg()));
	}
}
//#include <qdebug.h>
void clearLayout(QLayout* layout) {
	if (layout == NULL)
		return;
	QLayoutItem* item;
	while ((item = layout->takeAt(0))) {
		
		if (item->widget()) {
			delete item->widget();
		}
		delete item;
	}
}
void gui::reload_buttons()
{
	clearLayout(layout_lab);
	
	std::map<std::string, DTO> statistica = service.statistica();
	
	int i = 0;
	for (auto& it : statistica)
	{	
		QPushButton* tip = new QPushButton(QString::fromStdString(it.first));
	
		QObject::connect(tip, &QPushButton::clicked, this, [=]() {
			
			QMessageBox::information(this, "Numar de produse de acest tip", QString::number(it.second.get_nr()));

			});
		layout_lab->addWidget(tip);
		i++;
	}
	
}

Products_table::Products_table(Service& g, Wishlist_window* w) :s(g), wnd(w), QTableView() {  this->addObs(w); }
Products_table_list::Products_table_list  (Service& g, Wishlist_window* w) :s(g),wnd(w) { this->addObs(w); }


void Products_table::mouseDoubleClickEvent(QMouseEvent* event)
{

	if (this->selectionModel()->selectedIndexes().count() > 0 && (*wnd).isVisible())
	{
		int row = this->selectionModel()->selectedIndexes().at(0).row();
		auto cel0 = this->model()->index(row, 0);
		s.adauga_produs_cos(this->model()->data(cel0, 0).toString().toStdString());
		Observable::notify();
	}
	//if (this->selectedItems().count() > 0 && (*wnd).isVisible() )
	//{
	//	QList l = this->selectedItems();

	//	s.adauga_produs_cos(l[0]->data(0).toString().toStdString());
	//	//l2.notify();
	//	Observable::notify();


	//	//Observable::notify();
	//}
}
void Products_table_list::mouseDoubleClickEvent(QMouseEvent* event)
{

	if (this->selectedItems().count() > 0 && (*wnd).isVisible())
	{
		QList l= this->selectedItems();
		QList l2= l[0]->data(0).toString().split(' ');
		string nume = l2[0].toStdString();
		//string tip = l2[1].toStdString();
		//int pret = l2[2].toInt();
		//string producator = l2[3].toStdString();
		s.adauga_produs_cos(nume);
		//l2.notify();
		Observable::notify();


		//Observable::notify();
	}
}
Filter_window::Filter_window(gui& gs, std::string s) :g(gs), filtru(s) {
	this->setLayout(main_layout);
	form_for_filter->setLayout(layout_filter_new_window);
	this->setGeometry(50, 50, 720, 480);
	if (filtru == "name")
		layout_filter_new_window->addRow(name_filter_label, name_filter);
	else if(filtru=="price")
			layout_filter_new_window->addRow(price_filter_label, price_filter);
	else if(filtru=="manufacturer")
			layout_filter_new_window->addRow(manufacturer_filter_label, name_filter);
	main_layout->addWidget(form_for_filter);

}
void Filter_window::keyPressEvent(QKeyEvent* e)
{
	if (e->key() == 16777220)
	{
		std::vector<Produs> p;
		products_filtered = new QTableWidget(g.service.get_size_service(), 4);
		QStringList l;
		l << "Name" << "Type" << "Price" << "Manufacturer";
		products_filtered->setHorizontalHeaderLabels(l);
		products_filtered->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
		products_filtered->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

		filter = name_filter->text();
		if (name_filter->text().size())
		{

			if (name_filter->text().toStdString() == "name")
				p = g.service.filtrare_nume(name_filter->text().toStdString());
			else if (name_filter->text().toStdString() == "manufacturer");
				p = g.service.filtrare_producator(name_filter->text().toStdString());
			int count = 0;
			for (auto it = p.begin(); it != p.end(); it++)
				if ((*it).get_nume().size() == 0)
				{
					count++;

				}
			p.resize(p.size() - count);
			name_filter->clear();
			products_filtered->setRowCount(p.size());
		}
		else {
			filter = price_filter->text();
			if (filter.toInt())
			{

				p = g.service.filtrare_pret(filter.toInt());
				int count = 0;
				for (auto it = p.begin(); it != p.end(); it++)
					if ((*it).get_nume().size() == 0)
					{
						count++;

					}
				p.resize(p.size() - count);
				price_filter->clear();
				products_filtered->setRowCount(p.size());
			}

			}
	
	
		if (filter.size())
		{
			if (p.size())
			{
				int lines = 0;
				for (auto& it : p)

				{
					this->products_filtered->setItem(lines, 0, new QTableWidgetItem(QString::fromStdString(it.get_nume())));
					this->products_filtered->setItem(lines, 1, new QTableWidgetItem(QString::fromStdString(it.get_tip())));
					this->products_filtered->setItem(lines, 2, new QTableWidgetItem(QString::number(it.get_pret())));
					this->products_filtered->setItem(lines, 3, new QTableWidgetItem(QString::fromStdString(it.get_producator())));
					lines++;

					main_layout->addWidget(products_filtered);
					main_layout->addStretch();
				}
			}
			else {
				QMessageBox::warning(this, "Info", QString::fromStdString("No product found with the introduced data"));
			}
		}
		else {
			QMessageBox::warning(this, "Info", QString::fromStdString("No product found"));
		}

	}
}
Wishlist_window::Wishlist_window(gui& s,CrudCart_Window* crud):pr(s)
{
	this->addObs(crud);
	this->setLayout(main_layout);
	this->setGeometry(50, 50, 720, 480);
	left->setLayout(main_layout_wishlist);
	QStringList header;
	header << "Name" << "Type" << "Price" << "Manufacturer";
	table->setHorizontalHeaderLabels(header);
	table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	main_layout_wishlist->addRow(label);
	main_layout_wishlist->addWidget(table);

	right->setLayout(right_layout);
	right_layout->addStretch();
	right_layout->addWidget(generate);
	//right_layout->addWidget(number_of_products_to_generate);
	layout_slider->addWidget(number);
	layout_slider->addWidget(label_slider);
	right_layout->addLayout(layout_slider);
	
	layout_save_wishlist->addWidget(save);
	layout_save_wishlist->addRow(label_path,path);
	right_layout->addLayout(layout_save_wishlist);

	right_layout->addWidget(empty);
	right_layout->addStretch();



	main_layout->addWidget(left);
	main_layout->addWidget(right);
	connections();

}
void Wishlist_window::connections()
{
	QObject::connect(generate, &QPushButton::clicked, this, [&]() {
			
		int value = number->value();
		if (value == 0)
		{
			QMessageBox::warning(this, "Warning", QString::fromStdString("Please choose a valid number from the slider"));
		}
		else
		{
			pr.service.generare_cos(value);
			update();
			QMessageBox::information(this, "Info", QString::fromStdString("Cart generated successfully"));
			Observable::notify();
		}

		});
	QObject::connect(number, &QSlider::valueChanged, this, [&]() {
		
		label_slider->setText(QString::number(number->value()));
		
		});

	QObject::connect(save, &QPushButton::clicked, this, [&]() {

		QString str = path->text();
		if (str.size())
		{
			pr.service.salveaza_cos_service(str.toStdString());
			QMessageBox::information(this, "Info", QString::fromStdString("Cart saved successfully"));
		}
		else QMessageBox::warning(this, "Warning", QString::fromStdString("Type a valid path"));
		});
	QObject::connect(empty, &QPushButton::clicked, this, [&]() {
		try {
			pr.service.sterge_cos();
			update();
			QMessageBox::information(this, "Info", QString::fromStdString("Cart emptied successfully"));
			Observable::notify();
		}
		catch (RepoExceptions&){}
		
		});

}
void Wishlist_window::update() 
{
	table->setRowCount(pr.service.get_all_cos().size());
	int lines = 0;
	for (auto& it : pr.service.get_all_cos())

	{
		this->table->setItem(lines, 0, new QTableWidgetItem(QString::fromStdString(it.get_nume())));
		this->table->setItem(lines, 1, new QTableWidgetItem(QString::fromStdString(it.get_tip())));
		this->table->setItem(lines, 2, new QTableWidgetItem(QString::number(it.get_pret())));
		this->table->setItem(lines, 3, new QTableWidgetItem(QString::fromStdString(it.get_producator())));
		lines++;
	}
}
CrudCart_Window::CrudCart_Window(const gui& s):pr(s)
{
	crud_layout = new QHBoxLayout;
	this->setLayout(crud_layout);
	this->setGeometry(50, 50, 1024, 580);
	crud_table = new QTableWidget(0,4);
	QStringList header;
	header << "Name" << "Type" << "Price" << "Manufacturer";
	crud_table->setHorizontalHeaderLabels(header);
	crud_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

	

	generate_layout = new QHBoxLayout;
	number_crud = new QSpinBox;
	generate_crud_button = new QPushButton(QString::fromStdString("Generate cart"));
	generate_layout->addWidget(number_crud);
	generate_layout->addWidget(generate_crud_button);

	empty_crud_button = new QPushButton(QString::fromStdString("Empty cart"));
	right_crud_layout = new QVBoxLayout;
	right_crud_layout->addLayout(generate_layout);
	right_crud_layout->addWidget(empty_crud_button);

	crud_layout->addWidget(crud_table);
	crud_layout->addLayout(right_crud_layout);
	connections_crud();

}
void CrudCart_Window::connections_crud()
{
	QObject::connect(generate_crud_button, &QPushButton::clicked, this, [&]() {
		int value = number_crud->value();
		pr.service.generare_cos(value);
		update();
		this->notify();
		
		});
	QObject::connect(empty_crud_button, &QPushButton::clicked,this, [&]() {
		pr.service.sterge_cos();
		update();
		QMessageBox::information(this, "Info", QString::fromStdString("Deleted successfully"));
		Observable::notify();
		});


}
void CrudCart_Window::update()
{
	crud_table->setRowCount(pr.service.get_all_cos().size());
	int lines = 0;
	for (auto& it : pr.service.get_all_cos())

	{
		this->crud_table->setItem(lines, 0, new QTableWidgetItem(QString::fromStdString(it.get_nume())));
		this->crud_table->setItem(lines, 1, new QTableWidgetItem(QString::fromStdString(it.get_tip())));
		this->crud_table->setItem(lines, 2, new QTableWidgetItem(QString::number(it.get_pret())));
		this->crud_table->setItem(lines, 3, new QTableWidgetItem(QString::fromStdString(it.get_producator())));
		lines++;
	}



}
void ReadOnly_cart::update()
{
	QWidget::repaint();
}
void ReadOnly_cart::paintEvent(QPaintEvent* e)
{
	QPainter p(this);
	
	for (int i = 0; i < serv.get_all_cos().size(); i++)
	{
		std::mt19937 mt{ std::random_device{}() };
		std::uniform_int_distribution<> dist(100,480);
		int y = dist(mt);

		std::mt19937 mt2{ std::random_device{}() };
		std::uniform_int_distribution<> dist2(100,924);
		int x = dist2(mt2);
		p.drawRect(x, y, 100, 100);




	}

}