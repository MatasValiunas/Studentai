#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "header.hpp"

TEST_CASE("Stud klases funkcionalumo tikrinimas", "[Stud]") 
{
    Stud Studentas;

    REQUIRE(Studentas.getVard() == "");
    REQUIRE(Studentas.getPav() == "");
    SECTION("Vardo ir pavardes priskyrimas") {
        Studentas.setVard("Matas", "Valiunas");

        REQUIRE(Studentas.getVard() == "Matas");
        REQUIRE(Studentas.getPav() == "Valiunas");
    }

    SECTION("Galutinio balo priskyrimas") {
        Studentas.setGalut(10);

        REQUIRE(Studentas.getGalut() == 10);
    }

    SECTION("Pilnas klases inicializavimas") {
        Stud Studentas("Matas", "Valiunas", 10);

        REQUIRE(Studentas.getVard() == "Matas");
        REQUIRE(Studentas.getPav() == "Valiunas");
        REQUIRE(Studentas.getGalut() == 10);
    }
}