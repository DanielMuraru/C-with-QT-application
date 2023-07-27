#pragma once

#include <QtWidgets/QApplication>
//#include <QtWidgets/qmainwindow.h>
#include <qboxlayout.h>
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
#include "domain.h"
#include "service.h"
#include <vector>
#include <qabstractitemmodel.h>
#include <qabstractitemview.h>
#include <qtableview.h>
class table_model :public QAbstractTableModel
{

private:
	std::vector<Produs>& v;
public:
	table_model(QObject* parent, std::vector<Produs>& s) :QAbstractTableModel(parent), v(s) {}
	int rowCount(const QModelIndex &parent=QModelIndex())const override;
	int columnCount(const QModelIndex &parent=QModelIndex())const override;
	QVariant headerData(int section,Qt::Orientation orientation,int role) const override;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
	void setpro(std::vector<Produs>&);


};