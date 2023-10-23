#ifndef DATA_H
#define DATA_H


#include <QString>
#include <QStringList>
#include <QListWidgetItem>
#include <QHBoxLayout>
#include <QLabel>
typedef struct inform {
    QString nome;
    QString cognome;
    int stipendio;

    inform(QString nome, QString cognome, int stipendio)
    {
        this->nome=nome;
        this->cognome=cognome;
        this->stipendio=stipendio;
    }
} inform_t;

/*
class data {
private:

public:

};
*/
class CustomListItem : public QListWidgetItem {
public:
    CustomListItem(const QString& name, const QString& surname, int number) {
        QWidget* widget = new QWidget;
        QHBoxLayout* layout = new QHBoxLayout(widget);

        QLabel* nameLabel = new QLabel(name);
        QLabel* surnameLabel = new QLabel(surname);
        QLabel* numberLabel = new QLabel(QString::number(number));

        layout->addWidget(nameLabel);
        layout->addWidget(surnameLabel);
        layout->addWidget(numberLabel);

        widget->setLayout(layout);
        setSizeHint(widget->sizeHint());
        listWidget()->addItem(this);
        listWidget()->setItemWidget(this, widget);
    }
};
#endif // DATA_H
