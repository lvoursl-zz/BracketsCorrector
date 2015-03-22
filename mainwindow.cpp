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
        QString newStatementText;

        QVector<int> leftIndexes;
        QVector<int> rightIndexes;

        int left = 0, right = 0;
        for (int i = 0; i < statementText.length(); i++) {
            if (statementText.at(i) == '(') {
                newStatementText.push_back(statementText.at(i));
                leftIndexes.push_back(i);
                left++;
            } else if (statementText.at(i) == ')') {
                newStatementText.push_back(statementText.at(i));
                rightIndexes.push_back(i);
                right++;
            }
        }

        qDebug() << newStatementText;

        while ((rightIndexes.isEmpty() == false) && (leftIndexes.isEmpty() == false)) {
            /*statementText[leftIndexes.takeFirst()] = "<font color=\"DeepPink\">" + statementText[leftIndexes.first()] + "</font>";
            statementText[rightIndexes.length()] =  "<font color=\"DeepPink\">" + statementText[rightIndexes.last()] + "</font>";*/

            statementText = statementText.mid(0, leftIndexes.takeFirst()) + "<font color=\"DeepPink\">" + statementText.mid(leftIndexes.takeFirst(), leftIndexes.takeFirst()) + "</font>"
                            + statementText.mid(leftIndexes.takeFirst(), statementText.length() - 1);
            leftIndexes.pop_front();
            rightIndexes.pop_back();
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
