/*
Copyright (c) 2014 Raivis Strogonovs

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);    

    connect(ui->setKeyBtn, SIGNAL(clicked()), this, SLOT(setKey()));
    connect(ui->keyEdit,SIGNAL(returnPressed()), this, SLOT(setKey()));
    connect(ui->encryptBtn, SIGNAL(clicked()), this, SLOT(encyrptClicked()));
    connect(ui->decryptBtn, SIGNAL(clicked()), this, SLOT(decryptClicked()));

}

void MainWindow::encyrptClicked()
{
    qDebug() << QByteArray(ui->inputEdit->toHtml().toUtf8());
    QByteArray encyptedData = blowfish.encyrpt(  QByteArray(ui->inputEdit->toHtml().toUtf8()) );

    ui->statusBar->showMessage("Data encrypted!");
    ui->outputEdit->setHtml( encyptedData.toBase64() );
}


void MainWindow::decryptClicked()
{
    QByteArray decryptedData = blowfish.decrypt( QByteArray::fromBase64( QByteArray( ui->inputEdit->toPlainText().toUtf8() ) ) );

    ui->statusBar->showMessage("Data decrypted!");
    ui->outputEdit->setHtml( decryptedData );
}


void MainWindow::setKey()
{
    blowfish.calcSubKey( ui->keyEdit->text() );
    ui->statusBar->showMessage("Key has been set");
}

MainWindow::~MainWindow()
{
    delete ui;
}
