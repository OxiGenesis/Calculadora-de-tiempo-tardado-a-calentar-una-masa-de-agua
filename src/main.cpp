#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QMessageBox>
#include <QSpacerItem>

using namespace std;

void calcularTiempoCalentamiento(int temperaturaMaxima, int temperaturaInicial, int LitrosDeAgua, int PotenciaKW, int& TiempoTardado_HORAS, int& TiempoTardado_MINUTOS) {
    const double capacidadCalorifica = 4186.0;  // J/(kg·°C)
    const double masaPorLitro = 1.0;  // 1 litro de agua = 1 kg

    double deltaT = temperaturaMaxima - temperaturaInicial;
    double masaAgua = LitrosDeAgua * masaPorLitro;
    double energiaRequerida = masaAgua * capacidadCalorifica * deltaT;
    double potenciaW = PotenciaKW * 1000.0;
    double tiempoSegundos = energiaRequerida / potenciaW;

    TiempoTardado_HORAS = static_cast<int>(tiempoSegundos / 3600);
    TiempoTardado_MINUTOS = static_cast<int>((tiempoSegundos - (TiempoTardado_HORAS * 3600)) / 60);
}

class CalentadorApp : public QWidget {
public:
    CalentadorApp(QWidget *parent = nullptr);

private slots:
    void calcular();

private:
    QLineEdit *tempMaxLineEdit;
    QLineEdit *tempIniLineEdit;
    QLineEdit *litrosLineEdit;
    QLineEdit *potenciaLineEdit;
    QLabel *resultadoLabel;
    QLabel *versionLabel;
    QLabel *creadorLabel;

    QString version = "v1.0.0";  // Variable de versión
    QString creador = "By OxiGenesis";  // Variable del creador
};

CalentadorApp::CalentadorApp(QWidget *parent) : QWidget(parent) {
    // Establecer un diseño de ventana moderna con colores morados y negros
    setStyleSheet("background-color: #2c2c2c; color: #f0f0f0; font-family: 'Arial'; font-size: 14px;");

    // Crear los widgets
    tempMaxLineEdit = new QLineEdit(this);
    tempIniLineEdit = new QLineEdit(this);
    litrosLineEdit = new QLineEdit(this);
    potenciaLineEdit = new QLineEdit(this);
    QPushButton *calcularButton = new QPushButton("Calcular", this);
    resultadoLabel = new QLabel("Tiempo: ", this);
    versionLabel = new QLabel(version, this);  // Mostrar versión
    creadorLabel = new QLabel(creador, this);  // Mostrar creador

    // Estilo personalizado para los QLineEdit y el QPushButton
    tempMaxLineEdit->setPlaceholderText("Temperatura Máxima (°C)");
    tempMaxLineEdit->setStyleSheet("background-color: #3c3c3c; border: 1px solid #7f7f7f; padding: 5px;");
    tempIniLineEdit->setPlaceholderText("Temperatura Inicial (°C)");
    tempIniLineEdit->setStyleSheet("background-color: #3c3c3c; border: 1px solid #7f7f7f; padding: 5px;");
    litrosLineEdit->setPlaceholderText("Litros de Agua");
    litrosLineEdit->setStyleSheet("background-color: #3c3c3c; border: 1px solid #7f7f7f; padding: 5px;");
    potenciaLineEdit->setPlaceholderText("Potencia (kW)");
    potenciaLineEdit->setStyleSheet("background-color: #3c3c3c; border: 1px solid #7f7f7f; padding: 5px;");

    calcularButton->setStyleSheet("background-color: #6a0dad; color: white; border-radius: 5px; padding: 10px;");
    calcularButton->setFixedHeight(40);
    resultadoLabel->setStyleSheet("font-weight: bold; color: #9b59b6;");
    versionLabel->setStyleSheet("color: #8e44ad; font-size: 12px;");
    creadorLabel->setStyleSheet("color: #8e44ad; font-size: 12px;");

    // Layouts
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(tempMaxLineEdit);
    mainLayout->addWidget(tempIniLineEdit);
    mainLayout->addWidget(litrosLineEdit);
    mainLayout->addWidget(potenciaLineEdit);

    QSpacerItem *verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    mainLayout->addItem(verticalSpacer);

    mainLayout->addWidget(calcularButton);
    mainLayout->addWidget(resultadoLabel);

    QSpacerItem *spacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    mainLayout->addItem(spacer);

    mainLayout->addWidget(versionLabel);
    mainLayout->addWidget(creadorLabel);

    setLayout(mainLayout);

    // Conectar el botón de calcular a la función calcular()
    connect(calcularButton, &QPushButton::clicked, this, &CalentadorApp::calcular);
}

void CalentadorApp::calcular() {
    bool okTempMax, okTempIni, okLitros, okPotencia;
    int temperaturaMaxima = tempMaxLineEdit->text().toInt(&okTempMax);
    int temperaturaInicial = tempIniLineEdit->text().toInt(&okTempIni);
    int LitrosDeAgua = litrosLineEdit->text().toInt(&okLitros);
    int PotenciaKW = potenciaLineEdit->text().toInt(&okPotencia);

    // Validar que todos los valores sean números válidos
    if (!okTempMax || !okTempIni || !okLitros || !okPotencia) {
        QMessageBox::warning(this, "Entrada inválida", "Por favor ingrese valores válidos.");
        return;
    }

    int TiempoTardado_HORAS, TiempoTardado_MINUTOS;
    calcularTiempoCalentamiento(temperaturaMaxima, temperaturaInicial, LitrosDeAgua, PotenciaKW, TiempoTardado_HORAS, TiempoTardado_MINUTOS);

    // Mostrar el resultado
    resultadoLabel->setText(QString("Tiempo estimado: %1 horas y %2 minutos")
                             .arg(TiempoTardado_HORAS)
                             .arg(TiempoTardado_MINUTOS));
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Crear la ventana principal
    CalentadorApp ventana;
    ventana.setWindowTitle("Calculadora de Calentamiento de Agua");
    ventana.resize(350, 400);  // Ajustado el tamaño de la ventana
    ventana.setStyleSheet("QWidget { background-color: #2c2c2c; border-radius: 10px; padding: 20px; }");
    ventana.show();

    return app.exec();
}
