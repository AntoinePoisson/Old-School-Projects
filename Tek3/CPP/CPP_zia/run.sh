#!/bin/bash

arg="$1"

    # Argument help
if [[ "$arg" == "-h" || "$arg" == "-help" || "$arg" == "--help" ]];
then
    echo -e "Bash Script:"
    echo -e "USAGE:"
    echo -e "   ./run.sh          -> If necessary Build and Run Project"
    echo -e "   ./run.sh sudo     -> If necessary Build and Run Project as sudo"
    echo -e "   ./run.sh build    -> Only Build Project"
    echo -e "   ./run.sh debug    -> Run project with debug mode"
    echo -e "   ./run.sh re       -> Re-Build Project"
    echo -e "   ./run.sh clean    -> Remove Binary and Useless files"
    echo -e "   ./run.sh fclean   -> Remove Building files and Useless files"
    echo -e "   ./run.sh docker   -> Build and Run Project in Docker"
    echo -e "   ./run.sh deploy   -> Deploy apps online"
    echo -e "   ./run.sh tests    -> Build and Run unit tests"
    echo -e "   ./run.sh epitech  -> Push to Epitech"
    exit 0
fi

    # Argument build
if [[ "$arg" == "build" || "$arg" == "building" || "$arg" == "b" || "$arg" == "-b" ]];
then
    if [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
        if [[ ! -f "./cert.pem" || ! -f "./key.pem" ]];
        then
            echo -e '\n  \033[0;34m//[Need]: Generete SSL Certifica //\033[0m'
            echo -e "\n\n\n\n\n\n\n" | openssl req -x509 -nodes -days 365 -newkey rsa:1024 -keyout key.pem -out cert.pem
        fi
        if mkdir -p build && cd build && conan install .. --build=missing && clear && cmake .. -G "Unix Makefiles" && cmake --build . && make -j 4; then
            ln -sf ./build/bin/zia zia
            #clear
            echo -e '\n ~ \033[0;32mSuccess Build\033[0m ~'
        else
            echo -e '\n\033[0;31m /!\\ Failure Build /!\\\033[0m'
        fi
    else
        echo -e '\n ~ \033[0;32mSetup Conan ...\033[0m ~'
        pip install --upgrade pip
        pip install conan
        conan remote add bincraft https://api.bintray.com/conan/bincrafters/public-conan
        conan remote add epitech_remote https://api.bintray.com/conan/epitech/public-conan
        conan remote add conancenter https://api.bintray.com/conan/conan/conan-center
        conan profile new default --detect
        echo -e '\n ~ \033[0;32mBuilding Zia ...\033[0m ~'
        mkdir -p build
        cd build
        conan install ..
        cmake ..
        msbuild zia.vcxproj
        echo -e '\n ~ \033[0;32mSuccess Build\033[0m ~'
    fi
    exit 0
fi

    # Argument re
if [[ "$arg" == "re" || "$arg" == "rebuild" || "$arg" == "rebuilding" || "$arg" == "r" || "$arg" == "-r" || "$arg" == "-re" ]];
then
    if [ -d "./build/" ]; then
        rm -fr ./resources/log/*
        rm -f ./CMakeFiles/ ./CMakeCache.txt ./cmake_install.cmake ./zia run ./zia_tests
        rm -fr ./build/
        echo -e "\033[0;34m  [Done]: Remove Previous Build files.\033[0m"
    fi
    if [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
        if [[ ! -f "./cert.pem" || ! -f "./key.pem" ]];
        then
            echo -e '\n  \033[0;34m//[Need]: Generete SSL Certifica //\033[0m'
            echo -e "\n\n\n\n\n\n\n" | openssl req -x509 -nodes -days 365 -newkey rsa:1024 -keyout key.pem -out cert.pem
        fi
        if mkdir -p build && cd build && conan install .. --build=missing && clear && cmake .. -G "Unix Makefiles" && cmake --build . && make -j 4; then
            ln -sf ./build/bin/zia zia
            #clear
            echo -e '\n ~ \033[0;32mSuccess Re-Build\033[0m ~'
        else
            echo -e '\n\033[0;31m /!\\ Failure Re-Build /!\\\033[0m'
        fi
    else
        echo -e '\n ~ \033[0;32mSetup Conan ...\033[0m ~'
        pip install --upgrade pip
        pip install conan
        conan remote add bincraft https://api.bintray.com/conan/bincrafters/public-conan
        conan remote add epitech_remote https://api.bintray.com/conan/epitech/public-conan
        conan remote add conancenter https://api.bintray.com/conan/conan/conan-center
        conan profile new default --detect
        echo -e '\n ~ \033[0;32mBuilding Zia ...\033[0m ~'
        mkdir -p build
        cd build
        conan install ..
        cmake ..
        msbuild zia.vcxproj
        echo -e '\n ~ \033[0;32mSuccess Build\033[0m ~'
    fi
    exit 0
fi

    # Argument clean
if [[ "$arg" == "clean" || "$arg" == "clear" || "$arg" == "c" || "$arg" == "-c" ]];
then
    rm -fr ./resources/log/*.log
    rm -fr vgcore.*
    rm -fr *~ *.pem
    rm -fr \#*#
    rm -fr .#*
    rm -f ./CMakeFiles/ ./CMakeCache.txt ./cmake_install.cmake ./zia build/bin/zia run zia_tests
    echo -e "\033[0;34m  [Done]: Cleaning Binary and Useless files.\033[0m"
    exit 0
fi

    # Argument fclean
if [[ "$arg" == "fclean" || "$arg" == "fclear" || "$arg" == "fcl" || "$arg" == "fc" || "$arg" == "f" || "$arg" == "-f" ]];
then
    rm -fr ./resources/log/*
    rm -fr vgcore.* *~ \#*# .#* *.pem
    rm -f ./CMakeFiles/ ./CMakeCache.txt ./cmake_install.cmake ./zia run zia_tests
    rm -fr build/
    reset
    echo -e "\033[0;34m  [Done]: Cleaning Building files and Useless files.\033[0m"
    exit 0
fi

    # Argument docker
if [[ "$arg" == "docker" || "$arg" == "dock" || "$arg" == "do" || "$arg" == "-do" ]];
then
    docker build . -t zia
    echo -e '\n ~ \033[0;32mStart Docker\033[0m ~'
    docker run -i -t zia /bin/bash
    exit 0
fi

    # Argument deploy
if [[ "$arg" == "deploy" || "$arg" == "deploye" || "$arg" == "deployement" || "$arg" == "dep" || "$arg" == "-dep" ]];
then
    # username=""
    # password=""
    # ip=""
    # pathToRepo=""
    # sshpass -p $password scp ./* $username@$ip:$pathToRepo
    ## ?? Installer netstat ??
    # sshpass -p $password ssh $username@$ip "cd $pathToRepo ; echo -e '#!/bin/bash\nkill $(sudo netstat -ltnp | grep ":4200" | awk  "{print $7}" | cut -d "/" -f 1)' > .tmp ; bash .tmp ; rm -f .tmp ; ./run.sh $@ &"
    # echo -e '\n ~ \033[0;32mProject Deployed\033[0m ~'
    echo -e '\n\033[0;33m Deployement Will Coming Soon !!\033[0m'
    exit 0
fi

    # Argument test
if [[ "$arg" == "test" || "$arg" == "tests" || "$arg" == "unit_test" || "$arg" == "unit_tests" || "$arg" == "t" || "$arg" == "-t" || "$arg" == "tset" || "$arg" == "tet" ]];
then
    if [[ ! -d "./build/" || ! -f ./build/bin/zia_tests ]]; then
        echo -e '\n  \033[0;34m//Building Requirement://\033[0m'
        if [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
            if mkdir -p build && cd build && conan install .. --build=missing && clear && cmake .. -G "Unix Makefiles" && cmake --build . && make -j 4 tests_run; then
                ln -sf ./bin/zia_tests ../zia_tests
                echo -e '\n  \033[0;34m//[Done]: Build Tests//\033[0m'
            else
                echo -e '\n\033[0;31m  /!\\ Failure Build Tests /!\\\033[0m'
                exit 0
            fi
        else
            echo -e "\n\033[0;33m  Can't Build on this environnement !!\033[0m"
            exit 0
        fi
    else
        ln -sf ./build/bin/zia_tests zia_tests
        cd build && make -j 4 zia_tests
    fi
    ./bin/zia_tests && gcovr
    exit 0
fi

if [[ "$arg" == "epitech" || "$arg" == "Epitech" || "$arg" == "tek" || "$arg" == "epi" || "$arg" == "e" || "$arg" == "-e" ]];
then
    cd .github/workflows/
    ./remoteToEpitech.sh $2
    echo -e '\n  \033[0;34m//[Done]: Push to Epitech//\033[0m'
    exit 0
fi


######################################################################################
    ## Without Argument:

if [[ ! -f "./cert.pem" || ! -f "./key.pem" ]];
then
    echo -e '\n  \033[0;34m//[Need]: Generete SSL Certifica //\033[0m'
    echo -e "\n\n\n\n\n\n\n" | openssl req -x509 -nodes -days 365 -newkey rsa:1024 -keyout key.pem -out cert.pem
fi

    # Check If Necessity Building
if [[ ! -d "./build/" || ! -f ./build/bin/zia ]];
then
    echo -e '\n  \033[0;34m//Building Requirement://\033[0m'
    if [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
        if mkdir -p build && cd build && conan install .. --build=missing && clear && cmake .. -G "Unix Makefiles" && cmake --build . && make -j 4; then
            echo -e '\n  \033[0;34m//[Done]: Build//\033[0m'
            # reset
        else
            echo -e '\n\033[0;31m  /!\\ Failure Build /!\\\033[0m'
            exit 0
        fi
    else
        # Windows
        echo -e '\n ~ \033[0;32mSetup Conan ...\033[0m ~'
        pip install --upgrade pip
        pip install conan
        conan remote add bincraft https://api.bintray.com/conan/bincrafters/public-conan
        conan remote add epitech_remote https://api.bintray.com/conan/epitech/public-conan
        conan remote add conancenter https://api.bintray.com/conan/conan/conan-center
        conan profile new default --detect
        echo -e '\n ~ \033[0;32mBuilding Zia ...\033[0m ~'
        mkdir -p build
        cd build
        conan install ..
        cmake ..
        msbuild zia.vcxproj
        echo -e '\n ~ \033[0;32mSuccess Build\033[0m ~'
        exit 0
    fi
else
    cd build
        # Recompile
    if ! make -j 4; then
        echo -e '\n\033[0;31m  /!\\ Failure Build /!\\\033[0m'
        exit 0
    fi
    clear
fi
    #Go to root of repo
cd ..

    # Remove old log
if [[ "$arg" == "sudo" || "$arg" == "--sudo" || "$arg" == "su" || "$arg" == "-su" || "$arg" == "-s" ]];
then
    sudo rm -fr ./resources/log/*.log
else
    rm -fr ./resources/log/*.log
fi

    # Create log directory
mkdir -p ./resources/log/

    # Argument debug
if [[ "$arg" == "debug" || "$arg" == "Debug" || "$arg" == "bug" || "$arg" == "deb" || "$arg" == "-deb" ]];
then
    # valgrind --tool=memcheck --leak-check=full ./build/bin/zia
    if [[ "$2" == "sudo" || "$2" == "--sudo" || "$2" == "su" || "$2" == "-su" || "$2" == "-s" ]];
    then
        sudo valgrind ./build/bin/zia
    else
        valgrind ./build/bin/zia
    fi
    exit 0
fi

# Execute Zia
if [[ "$arg" == "sudo" || "$arg" == "--sudo" || "$arg" == "su" || "$arg" == "-su" || "$arg" == "-s" ]];
then
    sudo ./build/bin/zia
else
    ./build/bin/zia $@
fi
