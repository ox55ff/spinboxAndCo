#ifndef MYMODEL_H
#define MYMODEL_H

#include <QAbstractListModel>

class MyModel : public QAbstractListModel {
    Q_OBJECT

public:
    explicit MyModel(QObject* parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role) Q_DECL_OVERRIDE;

public:
    enum class Values : int {
        VAL1 = 0,
        VAL2,
        VAL3
    };

private:
    const int m_valueCount;

    int m_value1;

    int m_value2;
    int m_value3;

    // QAbstractItemModel interface
public:
    int columnCount(const QModelIndex& parent) const Q_DECL_OVERRIDE;
};

#endif // MYMODEL_H
