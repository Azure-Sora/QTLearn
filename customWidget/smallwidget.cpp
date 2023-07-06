#include "smallwidget.h"
#include "ui_smallwidget.h"
#include <QSpinBox>
#include <QSlider>

SmallWidget::SmallWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SmallWidget)
{
    ui->setupUi(this);

    connect(ui->spinBox, &QSpinBox::valueChanged, ui->horizontalSlider, &QSlider::setValue);

    connect(ui->horizontalSlider, &QSlider::valueChanged, ui->spinBox, &QSpinBox::setValue);
}

SmallWidget::~SmallWidget()
{
    delete ui;
}

void SmallWidget::setNum(int i)
{
    ui->spinBox->setValue(i);
}

int SmallWidget::getNum()
{
    return ui->spinBox->value();
}
