#include "TableModel.h"


int table_model::rowCount(const QModelIndex& /*parent*/) const
{
	return v.size();
}
int table_model::columnCount(const QModelIndex& /*parent*/) const
{
	return 4;
}
QVariant table_model::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole)
	{
		if (orientation == Qt::Horizontal)
		{
			if(section==0)
			return QString::fromStdString("Name");

			if (section == 1)
				return QString::fromStdString("Type");

			if (section == 2)
				return QString::fromStdString("Price");

			if (section == 3)
				return QString::fromStdString("Manufacturer");
		}
		else return QString::number(section);
	}
	return QVariant();
}
QVariant table_model::data(const QModelIndex &index, int role) const
{

	if (role == Qt::DisplayRole)
	{

		
		if(index.column()==0)
		return QString::fromStdString(v[index.row()].get_nume());

		if (index.column() == 1)
			return QString::fromStdString(v[index.row()].get_tip());

		if (index.column() == 2)
			return QString::number(v[index.row()].get_pret());

		if (index.column() == 3)
			return QString::fromStdString(v[index.row()].get_producator());
	}
	return QVariant();
}
void table_model::setpro(std::vector<Produs>& s)
{
	this->v=s;
	auto topLeft = createIndex(0, 0);
	auto bottomRight = createIndex(rowCount(), columnCount());
	emit layoutChanged();
	emit dataChanged(topLeft, bottomRight);
		
}