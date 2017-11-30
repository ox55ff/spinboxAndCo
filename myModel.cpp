#include "myModel.h"

MyModel::MyModel(QObject* parent)
    : QAbstractListModel(parent)
    , m_valueCount(3)
    , m_value1(10)
    , m_value2(20)
    , m_value3(30)
{
}

int MyModel::rowCount(const QModelIndex& parent) const
{
    if (parent.isValid())
        return 0;

    return m_valueCount;
}

QVariant MyModel::data(const QModelIndex& index, int) const
{
    int row = index.row();
    if (!index.isValid() || row < 0 || row > m_valueCount)
        return QVariant();

    switch (static_cast<Values>(row)) {
    case Values::VAL1:
        return m_value1;
    case Values::VAL2:
        return m_value2;
    case Values::VAL3:
        return m_value3;
    }

    return QVariant();
}

bool MyModel::setData(const QModelIndex& index, const QVariant& value, int)
{
    int row = index.row();
    if (!index.isValid() || row < 0 || row > m_valueCount)
        return false;

    int val = value.toInt();
    switch (static_cast<Values>(row)) {
    case Values::VAL1:
        m_value1 = val;
        break;
    case Values::VAL2:
        m_value2 = qMin(val, m_value3);
        break;
    case Values::VAL3:
        m_value3 = qMax(val, m_value2);
        break;
    }

    emit dataChanged(index, index);
    return true;
}

int MyModel::columnCount(const QModelIndex& parent) const
{
    if (parent.isValid())
        return 0;

    return 1;
}
