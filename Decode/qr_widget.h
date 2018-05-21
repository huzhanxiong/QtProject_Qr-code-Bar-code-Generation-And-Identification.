#ifndef QR_WIDGET
#define QR_WIDGET

#include <QWidget>


class qr_widget : public QWidget
{
    Q_OBJECT
public:
    explicit qr_widget(QWidget *paint = 0);

protected:
    void paintEvent(QPaintEvent *paint);

public:
    int ready_show = 0;
    QString code_text;
    int code_type = 0;
};


#endif // QR_WIDGET

