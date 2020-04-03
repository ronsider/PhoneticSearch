#include "PhoneticFinder.hpp"
#include <string>
using namespace phonetic;
using namespace std;

#include "doctest.h"


TEST_CASE("word misspellings") {
    CHECK(find("Hell","hell") == string("Hell"));
    CHECK(find("gocker","jokker") == string("gocker"));
    CHECK(find("zigzag","sigsag") == string("zigzag"));
    CHECK(find("Quit","qoyt") == string("Quit"));
    CHECK(find("DO","du")==string("DO"));
    CHECK(find("pig","big")==string("pig"));
    CHECK(find("computer","COMPUTER")==string("computer"));
    CHECK(find("MouSe","muoZE")==string("MouSe"));
    CHECK(find("pen","BEN")==string("pen"));
    CHECK(find("CABLE","kablE")==string("CABLE"));
    CHECK(find("sponge","sponje")==string("sponge"));
    CHECK(find("you","iUU")==string("you"));
    CHECK(find("she","SHE")==string("she"));
    CHECK(find("him","HYM")==string("him"));

}

TEST_CASE("long words cases") {
    CHECK(find("pulchritudinous","fulcHRITodinous") == string("pulchritudinous"));
    CHECK(find("Consanguineous","CunsanJuineous") == string("Consanguineous"));
    CHECK(find("ToysRus","doyzrOZ")==string("ToysRus"));
    CHECK(find("superPHARM","sUBERFARM")==string("superPHARM"));
    CHECK(find("gugugaga","GUGUjAJA")==string("gugugaga"));
    CHECK(find("Zombified","sombifieD")==string("Zombified"));
    CHECK(find("Trimmer","trimmer") == string("Trimmer"));
    CHECK(find("ChickenLittle","CHICKENliddlE") == string("ChickenLittle"));
    CHECK(find("hellogoodbye","HELLojoodPYe")==string("hellogoodbye"));
    CHECK(find("wikipedia","WIKifediA")==string("wikipedia"));
    CHECK(find("dinazour","tInaZOUR")==string("dinazour"));
    CHECK(find("DOwNLOAd","download")==string("DOwNLOAd"));
    CHECK(find("update","UBDATE")==string("update"));
    CHECK(find("sharingisCARING","sharingyzkarinJ")==string("sharingisCARING"));
    CHECK(find("OPTICANA","uptikana")==string("OPTICANA"));
    CHECK(find("KEYBOArd","keIpoART")==string("KEYBOArd"));
    CHECK(find("SPOngebob","sFonjefuF")==string("SPOngebob"));
    CHECK(find("settings","zeddinJz")==string("settings"));
    CHECK(find("isRAEL","ISRAEL")==string("isRAEL"));
}

TEST_CASE("very short word") {
    CHECK(find("j","g") == string("j"));
    CHECK(find("G","j") == string("G"));
    CHECK(find("G","J") == string("G"));
    CHECK(find("J","G") == string("J"));
    CHECK(find("v","w") == string("v"));
    CHECK(find("w","v") == string("w"));
    CHECK(find("f","b") == string("f"));
    CHECK(find("p","b") == string("p"));
    CHECK(find("f","p") == string("f"));  
    CHECK(find("i","y") == string("i"));
    CHECK(find("y","I") == string("y"));
    CHECK(find("Y","I") == string("Y"));
    CHECK(find("s","z") == string("s"));
    CHECK(find("S","z") == string("S"));
    CHECK(find("z","S") == string("z"));
    CHECK(find("q","k") == string("q"));
    CHECK(find("Q","C") == string("Q"));
    CHECK(find("K","C") == string("K"));
    CHECK(find("q","C") == string("q"));

}

TEST_CASE("replace by exersice criteria") {
    string text = "I love playing football";
    string text2 = "I am me";
    string text3 = "beautiful book";
    string text4= "angry big birds";
    string text5= "hello whats your name";
    string text6=  "leave me ALONE";
    string text7="FResh and clean";
    string text8="full Recharge";
    string text9="Cam scanner";
    string text10="undisputed CHAMPION";
    CHECK(find(text, "i") == string("I"));
    CHECK(find(text, "LUVe") == string("love"));
    CHECK(find(text, "FLAyinj") == string("playing"));
    CHECK(find(text, "FOOTBAll") == string("football"));
    CHECK(find(text2, "y") == string("I"));
    CHECK(find(text2, "AM") == string("am"));
    CHECK(find(text2, "mE") == string("me"));
    CHECK(find(text3, "peaotipuL") == string("beautiful"));
    CHECK(find(text3, "BOOq") == string("book"));
    CHECK(find(text4, "ANgri") == string("angry"));
    CHECK(find(text4, "piG") == string("big"));
    CHECK(find(text4, "BIRtz") == string("birds"));
    CHECK(find(text5, "hellu") == string("hello"));
    CHECK(find(text5, "vhadz") == string("whats"));
    CHECK(find(text5, "iour") == string("your"));
    CHECK(find(text5, "NAme") == string("name"));
    CHECK(find(text6, "leawe") == string("leave"));
    CHECK(find(text6, "Me") == string("me"));
    CHECK(find(text6, "aluNE") == string("ALONE"));
    CHECK(find(text7, "bresh") == string("FResh"));
    CHECK(find(text7, "AND") == string("and"));
    CHECK(find(text7, "qleaN") == string("clean"));
    CHECK(find(text8, "foll") == string("full"));
    CHECK(find(text8, "recharjE") == string("Recharge"));
    CHECK(find(text9, "kaM") == string("Cam"));
    CHECK(find(text9, "SQAnneR") == string("scanner"));
    CHECK(find(text10, "ontisbuTEt") == string("undisputed"));
    CHECK(find(text10, "qhaMPIun") == string("CHAMPION"));

}

TEST_CASE("lower upper case test") {
    string text = "HELLO MY DEAR FRIEND";
    string text2 = "THIS IS TEXT";
    string text3 = "HE LIKES WATCHING TV ALL BY HIMSELF";
    string text4="PIECE OF WHITE PAPER";
    CHECK(find(text, "hello") == string("HELLO"));
    CHECK(find(text, "my") == string("MY"));
    CHECK(find(text, "dear") == string("DEAR"));
    CHECK(find(text, "friend") == string("FRIEND"));
    CHECK(find(text2, "this") == string("THIS"));
    CHECK(find(text2, "iS") == string("IS"));
    CHECK(find(text2, "TEXt") == string("TEXT"));  
    CHECK(find(text3, "he") == string("HE")); 
    CHECK(find(text3, "likes") == string("LIKES")); 
    CHECK(find(text3, "watchinG") == string("WATCHING")); 
    CHECK(find(text3, "tv") == string("TV")); 
    CHECK(find(text3, "alL") == string("ALL")); 
    CHECK(find(text3, "bY") == string("BY")); 
    CHECK(find(text3, "himself") == string("HIMSELF")); 
    CHECK(find(text4, "PIECe") == string("PIECE"));
    CHECK(find(text4, "oF") == string("OF"));
    CHECK(find(text4, "WHIte") == string("WHITE"));
    CHECK(find(text4, "papEr") == string("PAPER"));
    CHECK(find(text4, "PapEr") == string("PAPER"));
    CHECK(find(text4, "pApEr") == string("PAPER"));
    CHECK(find(text4, "PAPEr") == string("PAPER"));
    CHECK(find(text4, "papeR") == string("PAPER"));
    CHECK(find(text4, "PIeCe") == string("PIECE"));
    CHECK(find(text4, "PiECe") == string("PIECE"));
    CHECK(find(text4, "pIECe") == string("PIECE"));
    CHECK(find(text4, "piECe") == string("PIECE"));
  
}
