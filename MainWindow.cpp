#include "MainWindow.h"
#include "myModel.h"
#include "ui_MainWindow.h"
#include <QDataWidgetMapper>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MyModel* model = new MyModel(this);
    QDataWidgetMapper* mapper = new QDataWidgetMapper(this);

    mapper->setOrientation(Qt::Vertical);
    mapper->setModel(model);

    mapper->addMapping(ui->sbVal1_1, static_cast<int>(MyModel::Values::VAL1));
    mapper->addMapping(ui->sldVal1_1, static_cast<int>(MyModel::Values::VAL1));

    mapper->addMapping(ui->sbVal1_2, static_cast<int>(MyModel::Values::VAL1));
    mapper->addMapping(ui->sldVal1_2, static_cast<int>(MyModel::Values::VAL1));

    mapper->addMapping(ui->sbVal2, static_cast<int>(MyModel::Values::VAL2));
    mapper->addMapping(ui->sbVal3, static_cast<int>(MyModel::Values::VAL3));

    mapper->toFirst();
}

MainWindow::~MainWindow()
{
    delete ui;
}
