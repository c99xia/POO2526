cmake_minimum_required(VERSION 4.0)
project(POO2526)

set(CMAKE_CXX_STANDARD 26)

add_executable(POO2526 main.cpp
        Controller/Comando.cpp
        Controller/ProcessaCMD.cpp
        Model/Jardim.cpp
        Model/Simulador.cpp
        Controller/Movimento/cmdEntraJardineiro.cpp
        Controller/Movimento/cmdMoveBaixo.cpp
        Controller/Movimento/cmdMoveCima.cpp
        Controller/Movimento/cmdMoveDireita.cpp
        Controller/Movimento/cmdMoveEsquerda.cpp
        Controller/Movimento/cmdSaiJardineiro.cpp
        Controller/Listar/cmdListarArea.cpp
        Controller/Listar/cmdListarCertaArea.cpp
        Controller/Listar/cmdListarFerramentas.cpp
        Controller/Listar/cmdListarPropriedadesPlantaPosicao.cpp
        Controller/Listar/cmdListarPlantasExistentesNoJardim.cpp
        Controller/Instante/cmdAvancaInstante.cpp
        Controller/EstadoJogo/cmdApagarEstadoJardim.cpp
        Controller/EstadoJogo/cmdCriarJardim.cpp
        Controller/EstadoJogo/cmdExecutaCmdTeste.cpp
        Controller/EstadoJogo/cmdFim.cpp
        Controller/EstadoJogo/cmdGravarEstadoJardim.cpp
        Controller/EstadoJogo/cmdRecuperarEstadoJardim.cpp
        Controller/Acao/cmdColherPlanta.cpp
        Controller/Acao/cmdComprarFerramenta.cpp
        Controller/Acao/cmdLargarFerramenta.cpp
        Controller/Acao/cmdPegarFerramenta.cpp
        Controller/Acao/cmdPlantar.cpp
        View/Interface.cpp
        Utils/Settings.h
        Model/Beleza.h
        Model/Plantas/Roseira.h
        Model/Plantas/Roseira.cpp
        Model/Posicao.cpp
        Utils/Random.cpp
        Utils/Random.h
        Model/Plantas/Planta.cpp
        Model/Plantas/Cacto.h
        Model/Plantas/Cacto.cpp
        Utils/Tempo.cpp
        Utils/Tempo.h
        Model/Plantas/Daninha.cpp
        Model/Plantas/M4rg4rid4.cpp
        Model/Jardineiro.cpp
        Model/Ferramentas/Ferramenta.cpp
        Model/Ferramentas/Regador.h
        Model/Ferramentas/Regador.cpp
        Model/Ferramentas/Adubo.h
        Model/Ferramentas/Adubo.cpp
        Model/Ferramentas/Tesoura.h
        Model/Ferramentas/Tesoura.cpp
        Model/Ferramentas/Trator.cpp
)
