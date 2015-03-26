#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_testButton_clicked()
{
    if (ui->statementText->toPlainText().isEmpty() != true) {

        QString statementText = ui->statementText->toPlainText();
        QVector<QString> brackets;

        int left = 0, right = 0;

        for (int i = 0; i < statementText.length(); i++) {
            if (statementText.at(i) == '(') {
                brackets.push_back(statementText.at(i));
                left++;
            } else if (statementText.at(i) == ')') {
                brackets.push_back(statementText.at(i));
                right++;
            }
        }

        qDebug() << brackets.length() << endl;
        //qDebug() << statementText.mid(0, 1) << statementText.mid(2, 0);

        int randomNum;
        QString randomColor;

        for (int i = 0; i < brackets.length() / 2; i++) {
            randomNum = rand() % 999999 + 111111;
            randomColor = "#" + QString::number(randomNum);                        
            brackets[i] = "<font color=\"" + randomColor + "\">" + brackets[i] + "</font>";
            brackets[brackets.length() - 1 - i] = "<font color=\"" + randomColor + "\">"
                                                    + brackets[brackets.length() - 1 - i]
                                                    + "</font>";

            //ui->statementLabel->setText( brackets[i]);
            //qDebug() << brackets[i] << brackets[brackets.length() - 1 - i] << endl;
        }

        for (int i = 0; i < brackets.length(); ++i) {
            qDebug() << brackets[i] << endl;
        }

        for (int i = 0; i < statementText.length(); i++) {
            if (((statementText.at(i) == '(') || (statementText.at(i) == ')')) && (!brackets.isEmpty())) {
                statementText = statementText.mid(0, i) + brackets.takeFirst()
                                + statementText.mid(i + 1, statementText.length());
                i += 29;
                qDebug() << statementText << endl;
            }
        }

        ui->statementLabel->setText(statementText);

        if (left > right) {
            ui->resultLabel->setText("<font color=\"#0000ff\">left more than right for " + QString::number(left - right));
        } else if (right > left) {
            ui->resultLabel->setText("right more than left for " + QString::number(right - left));
        } else if ((right == left) && (left != 0) && (right != 0)) {
            ui->resultLabel->setText("Fine!");
        } else {
            ui->resultLabel->clear();
        }


    }
}
