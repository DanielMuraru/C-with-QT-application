//#include "Project1_QT.h"
#include <QtWidgets/QApplication>
#include "service.h"
#include "Repofile.h"
#include "RepoLabb.h"
#include "Validator.h"
#include "cos.h"
#include "GUI.h"
#include "teste.h"
#include "teste_cos.h"
#include "teste_repo_lab.h"
void run_tests_all()
{
    run_tests();
    run_teste_cos();
    run_teste_lab();
}
int main(int argc, char *argv[])
{
    
    QApplication a(argc, argv);
    Repof repo{"date.csv"};
    //RepoLab repo{0.9};
    Validator val;
    Cos coss;
    run_tests_all();

    Service s{ coss,repo,val };
    gui ui{ s };
    ui.show();
    return a.exec();
}
