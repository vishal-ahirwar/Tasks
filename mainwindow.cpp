//copyright(c) vishal ahirwar.all rights reserved.
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<iostream>
#include<fstream>
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  ui->textEdit->setTextColor(QColor(Qt::white));

}

MainWindow::~MainWindow()
{
  delete ui;
}


void MainWindow::on_pushButton_clicked()
{
  QColor background_color=QColorDialog::getColor(Qt::yellow,this);
  ui->textEdit->setTextColor(background_color);
}


void MainWindow::on_pushButton_2_clicked()
{
  bool ok;
    QFont text_font=QFontDialog::getFont(&ok);
    if(ok)
    ui->textEdit->setFont(text_font);
}


void MainWindow::on_pushButton_3_clicked()
{
    std::ifstream file("task.tx",std::ios_base::in);
    if(file.is_open())
      {

        QString tasks{};
          while(!file.eof())

            {
              std::string temp{};
              file>>temp;
              tasks.append(temp.c_str());
            };

          this->ui->textEdit->setText(tasks);
          this->ui->textEdit->setTextColor(QColor(Qt::white));


      }else
      {
            QMessageBox::information(this,"[Error]No task.tx file found!","Please First Type  tasks then make it read only so it can be saved!");
      }
 };



void MainWindow::on_checkBox_4_stateChanged(int arg1)
{
    this->ui->textEdit->setReadOnly(arg1);

      std::ofstream file("task.tx",std::ios_base::out);
      if(file.is_open())
        {
          file<<this->ui->textEdit->toPlainText().toStdString();
        };
      file.close();


}

