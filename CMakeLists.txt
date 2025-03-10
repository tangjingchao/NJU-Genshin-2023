include_directories("C:/Users/5-1-302/Downloads/SDL2-devel-2.28.5-mingw.zip/SDL2-2.28.5/x86_64-w64-mingw32/include")
link_directories("C:/Users/5-1-302/Downloads/SDL2-devel-2.28.5-mingw.zip/SDL2-2.28.5/x86_64-w64-mingw32/lib")

add_executable(2023-project
        main.c
        operate/partI.h
        operate/partI.c
        operate/partII.h
        operate/partII.c
        operate/partIII.h
        operate/partIII.c
        main main.c operate/partI.c operate/partII.c operate/partIII.c
)

target_link_libraries(2023-project
        mingw32
        SDL2main
        SDL2
        SDL2_image
        SDL2_ttf
        SDL2_mixer
)