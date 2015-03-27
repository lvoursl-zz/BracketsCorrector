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


bool isBracketInArray(QVector<QString> brackets) {
    for (int i = 0; i < brackets.length(); i++) {
        if ((brackets[i] == "(") || (brackets[i] == ")")) return true;
    }

    return false;
}

int findLastLeftBracket(QVector<QString> brackets) {
    int index = -1;
    for (int i = 0; i < brackets.length(); i++) {
        if (brackets[i] == "(") index = i;
    }

    return index;
}

int findFirstRightBracket(QVector<QString> brackets) {
    for (int i = 0; i < brackets.length(); i++) {
        if (brackets[i] == ")") return i;
    }

    return -1;
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

        qDebug() << brackets.length() << endl << isBracketInArray(brackets);
        //qDebug() << statementText.mid(0, 1) << statementText.mid(2, 0);

        int randomNum;
        QString randomColor;

        for (int i = 0; i < brackets.length() - 1; i++) {
            randomNum = rand() % 999999 + 111111;
            randomColor = "#" + QString::number(randomNum);

            if ((brackets[i] == "(") && (brackets[i + 1] == ")")) {
                 brackets[i] = "<font color=\"" + randomColor + "\"FONT SIZE = 5>" + brackets[i] + "</font>";
                 brackets[i + 1] = "<font color=\"" + randomColor + "\"FONT SIZE = 5>" + brackets[i + 1] + "</font>";
            }
        }

        int lastLeftBracketIndex = -1;
        int firstRightBrackeIndex = -1;

        int A, B, C;
        A = 5.6;
        B = 7.3;
        C = 0;

        bool G = (A && B) || (B && C);
        qDebug() << "G" << G;

        while (isBracketInArray(brackets)) {
            lastLeftBracketIndex = findLastLeftBracket(brackets);
            firstRightBrackeIndex = findFirstRightBracket(brackets);

            if ((lastLeftBracketIndex != -1) && (firstRightBrackeIndex != -1)) {
                randomNum = rand() % 999999 + 111111;
                randomColor = "#" + QString::number(randomNum);

                brackets[lastLeftBracketIndex] = "<font color=\"" + randomColor + "\"FONT SIZE = 5>"
                                                 + brackets[lastLeftBracketIndex] + "</font>";
                brackets[firstRightBrackeIndex] = "<font color=\"" + randomColor + "\"FONT SIZE = 5>"
                                                 + brackets[firstRightBrackeIndex] + "</font>";
            } else {
                break;
            }

        }

        for (int i = 0; i < brackets.length(); ++i) {
            qDebug() << brackets[i] << endl;
        }

        int length = 0;
        for (int i = 0; i < statementText.length(); i++) {
            if (((statementText.at(i) == '(') || (statementText.at(i) == ')')) && (!brackets.isEmpty())) {
                length = brackets.first().length();

                statementText = statementText.mid(0, i) + brackets.takeFirst()
                                + statementText.mid(i + 1, statementText.length());

                if (length != 1) i += 35;
                qDebug() << statementText << endl;
            }
        }

        ui->statementLabel->setText(statementText);

        if (left > right) {
            ui->resultLabel->setText("<font color=\"#0000ff\" FONT SIZE = 5>left more than right for " + QString::number(left - right));
        } else if (right > left) {
            ui->resultLabel->setText("right more than left for " + QString::number(right - left));
        } else if ((right == left) && (left != 0) && (right != 0)) {
            ui->resultLabel->setText("Fine!");
        } else {
            ui->resultLabel->clear();
        }


    }
}


