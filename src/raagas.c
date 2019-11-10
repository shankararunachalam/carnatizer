#include "types.h"

// carnatic melakartha raagas

const typedef struct raaga {
  const char *name;
  const u8 melakartha_id;
  const char *aarohana_note[8];
  const char *avarohana_note[8];
  const u8 aarohana_interval[7];
  const u8 avarohana_interval[7];
} raaga;

const raaga melakartha_raga[72] = {
    { "Kanakaangi", 1, {"S", "R1", "G1", "M1", "P", "D1", "N1", "S."}, {"S.", "N1", "D1", "P", "M1", "G1", "R1", "S"}, {1, 1, 3, 2, 1, 1, 3}, {3, 1, 1, 2, 3, 1, 1} },
    { "Rathnaangi", 2, {"S", "R1", "G1", "M1", "P", "D1", "N2", "S."}, {"S.", "N2", "D1", "P", "M1", "G1", "R1", "S"}, {1, 1, 3, 2, 1, 2, 2}, {2, 2, 1, 2, 3, 1, 1} },
    { "Gaanamoorti", 3, {"S", "R1", "G1", "M1", "P", "D1", "N3", "S."}, {"S.", "N3", "D1", "P", "M1", "G1", "R1", "S"}, {1, 1, 3, 2, 1, 3, 1}, {1, 3, 1, 2, 3, 1, 1} },
    { "Vanaspati", 4, {"S", "R1", "G1", "M1", "P", "D2", "N2", "S."}, {"S.", "N2", "D2", "P", "M1", "G1", "R1", "S"}, {1, 1, 3, 2, 2, 1, 2}, {2, 1, 2, 2, 3, 1, 1} },
    { "Maanavati", 5, {"S", "R1", "G1", "M1", "P", "D2", "N3", "S."}, {"S.", "N3", "D2", "P", "M1", "G1", "R1", "S"}, {1, 1, 3, 2, 2, 2, 1}, {1, 2, 2, 2, 3, 1, 1} },
    { "Taanaroopi", 6, {"S", "R1", "G1", "M1", "P", "D3", "N3", "S."}, {"S.", "N3", "D3", "P", "M1", "G1", "R1", "S"}, {1, 1, 3, 2, 3, 1, 1}, {1, 1, 3, 2, 3, 1, 1} },
    { "Senaavati", 7, {"S", "R1", "G2", "M1", "P", "D1", "N1", "S."}, {"S.", "N1", "D1", "P", "M1", "G2", "R1", "S"}, {1, 2, 2, 2, 1, 1, 3}, {3, 1, 1, 2, 2, 2, 1} },
    { "Hanumatodi", 8, {"S", "R1", "G2", "M1", "P", "D1", "N2", "S."}, {"S.", "N2", "D1", "P", "M1", "G2", "R1", "S"}, {1, 2, 2, 2, 1, 2, 2}, {2, 2, 1, 2, 2, 2, 1} },
    { "Dhenuka", 9, {"S", "R1", "G2", "M1", "P", "D1", "N3", "S."}, {"S.", "N3", "D1", "P", "M1", "G2", "R1", "S"}, {1, 2, 2, 2, 1, 3, 1}, {1, 3, 1, 2, 2, 2, 1} },
    { "Naatakapriya", 10, {"S", "R1", "G2", "M1", "P", "D2", "N2", "S."}, {"S.", "N2", "D2", "P", "M1", "G2", "R1", "S"}, {1, 2, 2, 2, 2, 1, 2}, {2, 1, 2, 2, 2, 2, 1} },
    { "Kokilapriyaa", 11, {"S", "R1", "G2", "M1", "P", "D2", "N3", "S."}, {"S.", "N3", "D2", "P", "M1", "G2", "R1", "S"}, {1, 2, 2, 2, 2, 2, 1}, {1, 2, 2, 2, 2, 2, 1} },
    { "Rupavati", 12, {"S", "R1", "G2", "M1", "P", "D3", "N3", "S."}, {"S.", "N3", "D3", "P", "M1", "G2", "R1", "S"}, {1, 2, 2, 2, 3, 1, 1}, {1, 1, 3, 2, 2, 2, 1} },
    { "Gaayakapriya", 13, {"S", "R1", "G3", "M1", "P", "D1", "N1", "S."}, {"S.", "N1", "D1", "P", "M1", "G3", "R1", "S"}, {1, 3, 1, 2, 1, 1, 3}, {3, 1, 1, 2, 1, 3, 1} },
    { "Vakulaabharanam", 14, {"S", "R1", "G3", "M1", "P", "D1", "N2", "S."}, {"S.", "N2", "D1", "P", "M1", "G3", "R1", "S"}, {1, 3, 1, 2, 1, 2, 2}, {2, 2, 1, 2, 1, 3, 1} },
    { "Maayamaalava Gowla", 15, {"S", "R1", "G3", "M1", "P", "D1", "N3", "S."}, {"S.", "N3", "D1", "P", "M1", "G3", "R1", "S"}, {1, 3, 1, 2, 1, 3, 1}, {1, 3, 1, 2, 1, 3, 1} },
    { "Chakravaakam", 16, {"S", "R1", "G3", "M1", "P", "D2", "N2", "S."}, {"S.", "N2", "D2", "P", "M1", "G3", "R1", "S"}, {1, 3, 1, 2, 2, 1, 2}, {2, 1, 2, 2, 1, 3, 1} },
    { "Sooryakaantam", 17, {"S", "R1", "G3", "M1", "P", "D2", "N3", "S."}, {"S.", "N3", "D2", "P", "M1", "G3", "R1", "S"}, {1, 3, 1, 2, 2, 2, 1}, {1, 2, 2, 2, 1, 3, 1} },
    { "Hatakaambari", 18, {"S", "R1", "G3", "M1", "P", "D3", "N3", "S."}, {"S.", "N3", "D3", "P", "M1", "G3", "R1", "S"}, {1, 3, 1, 2, 3, 1, 1}, {1, 1, 3, 2, 1, 3, 1} },
    { "Jhankaaradhvani", 19, {"S", "R2", "G2", "M1", "P", "D1", "N1", "S."}, {"S.", "N1", "D1", "P", "M1", "G2", "R2", "S"}, {2, 1, 2, 2, 1, 1, 3}, {3, 1, 1, 2, 2, 1, 2} },
    { "Natabhairavi", 20, {"S", "R2", "G2", "M1", "P", "D1", "N2", "S."}, {"S.", "N2", "D1", "P", "M1", "G2", "R2", "S"}, {2, 1, 2, 2, 1, 2, 2}, {2, 2, 1, 2, 2, 1, 2} },
    { "Keeravaani", 21, {"S", "R2", "G2", "M1", "P", "D1", "N3", "S."}, {"S.", "N3", "D1", "P", "M1", "G2", "R2", "S"}, {2, 1, 2, 2, 1, 3, 1}, {1, 3, 1, 2, 2, 1, 2} },
    { "Kharaharapriya", 22, {"S", "R2", "G2", "M1", "P", "D2", "N2", "S."}, {"S.", "N2", "D2", "P", "M1", "G2", "R2", "S"}, {2, 1, 2, 2, 2, 1, 2}, {2, 1, 2, 2, 2, 1, 2} },
    { "Gowri Manohari", 23, {"S", "R2", "G2", "M1", "P", "D2", "N3", "S."}, {"S.", "N3", "D2", "P", "M1", "G2", "R2", "S"}, {2, 1, 2, 2, 2, 2, 1}, {1, 2, 2, 2, 2, 1, 2} },
    { "Varunapriyaa", 24, {"S", "R2", "G2", "M1", "P", "D3", "N3", "S."}, {"S.", "N3", "D3", "P", "M1", "G2", "R2", "S"}, {2, 1, 2, 2, 3, 1, 1}, {1, 1, 3, 2, 2, 1, 2} },
    { "Maararanjani", 25, {"S", "R2", "G3", "M1", "P", "D1", "N1", "S."}, {"S.", "N1", "D1", "P", "M1", "G3", "R2", "S"}, {2, 2, 1, 2, 1, 1, 3}, {3, 1, 1, 2, 1, 2, 2} },
    { "Chaarukeshi", 26, {"S", "R2", "G3", "M1", "P", "D1", "N2", "S."}, {"S.", "N2", "D1", "P", "M1", "G3", "R2", "S"}, {2, 2, 1, 2, 1, 2, 2}, {2, 2, 1, 2, 1, 2, 2} },
    { "Sarasaangi", 27, {"S", "R2", "G3", "M1", "P", "D1", "N3", "S."}, {"S.", "N3", "D1", "P", "M1", "G3", "R2", "S"}, {2, 2, 1, 2, 1, 3, 1}, {1, 3, 1, 2, 1, 2, 2} },
    { "Harikaambhoji", 28, {"S", "R2", "G3", "M1", "P", "D2", "N2", "S."}, {"S.", "N2", "D2", "P", "M1", "G3", "R2", "S"}, {2, 2, 1, 2, 2, 1, 2}, {2, 1, 2, 2, 1, 2, 2} },
    { "Shankaraabharanam", 29, {"S", "R2", "G3", "M1", "P", "D2", "N3", "S."}, {"S.", "N3", "D2", "P", "M1", "G3", "R2", "S"}, {2, 2, 1, 2, 2, 2, 1}, {1, 2, 2, 2, 1, 2, 2} },
    { "Naaganandhini", 30, {"S", "R2", "G3", "M1", "P", "D3", "N3", "S."}, {"S.", "N3", "D3", "P", "M1", "G3", "R2", "S"}, {2, 2, 1, 2, 3, 1, 1}, {1, 1, 3, 2, 1, 2, 2} },
    { "Yaagapriyaa", 31, {"S", "R3", "G3", "M1", "P", "D1", "N1", "S."}, {"S.", "N1", "D1", "P", "M1", "G3", "R3", "S"}, {3, 1, 1, 2, 1, 1, 3}, {3, 1, 1, 2, 1, 1, 3} },
    { "Raagavardhani", 32, {"S", "R3", "G3", "M1", "P", "D1", "N2", "S."}, {"S.", "N2", "D1", "P", "M1", "G3", "R3", "S"}, {3, 1, 1, 2, 1, 2, 2}, {2, 2, 1, 2, 1, 1, 3} },
    { "Gangeyabhushani", 33, {"S", "R3", "G3", "M1", "P", "D1", "N3", "S."}, {"S.", "N3", "D1", "P", "M1", "G3", "R3", "S"}, {3, 1, 1, 2, 1, 3, 1}, {1, 3, 1, 2, 1, 1, 3} },
    { "Vaagadeeshwari", 34, {"S", "R3", "G3", "M1", "P", "D2", "N2", "S."}, {"S.", "N2", "D2", "P", "M1", "G3", "R3", "S"}, {3, 1, 1, 2, 2, 1, 2}, {2, 1, 2, 2, 1, 1, 3} },
    { "Shulini", 35, {"S", "R3", "G3", "M1", "P", "D2", "N3", "S."}, {"S.", "N3", "D2", "P", "M1", "G3", "R3", "S"}, {3, 1, 1, 2, 2, 2, 1}, {1, 2, 2, 2, 1, 1, 3} },
    { "Chalanaattai", 36, {"S", "R3", "G3", "M1", "P", "D3", "N3", "S."}, {"S.", "N3", "D3", "P", "M1", "G3", "R3", "S"}, {3, 1, 1, 2, 3, 1, 1}, {1, 1, 3, 2, 1, 1, 3} },
    { "Saalagam", 37, {"S", "R1", "G1", "M2", "P", "D1", "N1", "S."}, {"S.", "N1", "D1", "P", "M2", "G1", "R1", "S"}, {1, 1, 4, 1, 1, 1, 3}, {3, 1, 1, 1, 4, 1, 1} },
    { "Jalaarnavam", 38, {"S", "R1", "G1", "M2", "P", "D1", "N2", "S."}, {"S.", "N2", "D1", "P", "M2", "G1", "R1", "S"}, {1, 1, 4, 1, 1, 2, 2}, {2, 2, 1, 1, 4, 1, 1} },
    { "Jhaalavaraali", 39, {"S", "R1", "G1", "M2", "P", "D1", "N3", "S."}, {"S.", "N3", "D1", "P", "M2", "G1", "R1", "S"}, {1, 1, 4, 1, 1, 3, 1}, {1, 3, 1, 1, 4, 1, 1} },
    { "Navaneetham", 40, {"S", "R1", "G1", "M2", "P", "D2", "N2", "S."}, {"S.", "N2", "D2", "P", "M2", "G1", "R1", "S"}, {1, 1, 4, 1, 2, 1, 2}, {2, 1, 2, 1, 4, 1, 1} },
    { "Paavani", 41, {"S", "R1", "G1", "M2", "P", "D2", "N3", "S."}, {"S.", "N3", "D2", "P", "M2", "G1", "R1", "S"}, {1, 1, 4, 1, 2, 2, 1}, {1, 2, 2, 1, 4, 1, 1} },
    { "Raghupriyaa", 42, {"S", "R1", "G1", "M2", "P", "D3", "N3", "S."}, {"S.", "N3", "D3", "P", "M2", "G1", "R1", "S"}, {1, 1, 4, 1, 3, 1, 1}, {1, 1, 3, 1, 4, 1, 1} },
    { "Ghavaambhodi", 43, {"S", "R1", "G2", "M2", "P", "D1", "N1", "S."}, {"S.", "N1", "D1", "P", "M2", "G2", "R1", "S"}, {1, 2, 3, 1, 1, 1, 3}, {3, 1, 1, 1, 3, 2, 1} },
    { "Bhavapriya", 44, {"S", "R1", "G2", "M2", "P", "D1", "N2", "S."}, {"S.", "N2", "D1", "P", "M2", "G2", "R1", "S"}, {1, 2, 3, 1, 1, 2, 2}, {2, 2, 1, 1, 3, 2, 1} },
    { "Shubhapanthuvaraali", 45, {"S", "R1", "G2", "M2", "P", "D1", "N3", "S."}, {"S.", "N3", "D1", "P", "M2", "G2", "R1", "S"}, {1, 2, 3, 1, 1, 3, 1}, {1, 3, 1, 1, 3, 2, 1} },
    { "Shadvidhamaargini", 46, {"S", "R1", "G2", "M2", "P", "D2", "N2", "S."}, {"S.", "N2", "D2", "P", "M2", "G2", "R1", "S"}, {1, 2, 3, 1, 2, 1, 2}, {2, 1, 2, 1, 3, 2, 1} },
    { "Suvarnaangi", 47, {"S", "R1", "G2", "M2", "P", "D2", "N3", "S."}, {"S.", "N3", "D2", "P", "M2", "G2", "R1", "S"}, {1, 2, 3, 1, 2, 2, 1}, {1, 2, 2, 1, 3, 2, 1} },
    { "Divyamani", 48, {"S", "R1", "G2", "M2", "P", "D3", "N3", "S."}, {"S.", "N3", "D3", "P", "M2", "G2", "R1", "S"}, {1, 2, 3, 1, 3, 1, 1}, {1, 1, 3, 1, 3, 2, 1} },
    { "Dhavalaambari", 49, {"S", "R1", "G3", "M2", "P", "D1", "N1", "S."}, {"S.", "N1", "D1", "P", "M2", "G3", "R1", "S"}, {1, 3, 2, 1, 1, 1, 3}, {3, 1, 1, 1, 2, 3, 1} },
    { "Naamanaaraayani", 50, {"S", "R1", "G3", "M2", "P", "D1", "N2", "S."}, {"S.", "N2", "D1", "P", "M2", "G3", "R1", "S"}, {1, 3, 2, 1, 1, 2, 2}, {2, 2, 1, 1, 2, 3, 1} },
    { "Panthuvaraali", 51, {"S", "R1", "G3", "M2", "P", "D1", "N3", "S."}, {"S.", "N3", "D1", "P", "M2", "G3", "R1", "S"}, {1, 3, 2, 1, 1, 3, 1}, {1, 3, 1, 1, 2, 3, 1} },
    { "Raamapriyaa", 52, {"S", "R1", "G3", "M2", "P", "D2", "N2", "S."}, {"S.", "N2", "D2", "P", "M2", "G3", "R1", "S"}, {1, 3, 2, 1, 2, 1, 2}, {2, 1, 2, 1, 2, 3, 1} },
    { "Gamanashrama", 53, {"S", "R1", "G3", "M2", "P", "D2", "N3", "S."}, {"S.", "N3", "D2", "P", "M2", "G3", "R1", "S"}, {1, 3, 2, 1, 2, 2, 1}, {1, 2, 2, 1, 2, 3, 1} },
    { "Vishvaambhari", 54, {"S", "R1", "G3", "M2", "P", "D3", "N3", "S."}, {"S.", "N3", "D3", "P", "M2", "G3", "R1", "S"}, {1, 3, 2, 1, 3, 1, 1}, {1, 1, 3, 1, 2, 3, 1} },
    { "Shyaamalaangi", 55, {"S", "R2", "G2", "M2", "P", "D1", "N1", "S."}, {"S.", "N1", "D1", "P", "M2", "G2", "R2", "S"}, {2, 1, 3, 1, 1, 1, 3}, {3, 1, 1, 1, 3, 1, 2} },
    { "Shanmukhapriyaa", 56, {"S", "R2", "G2", "M2", "P", "D1", "N2", "S."}, {"S.", "N2", "D1", "P", "M2", "G2", "R2", "S"}, {2, 1, 3, 1, 1, 2, 2}, {2, 2, 1, 1, 3, 1, 2} },
    { "Simhendramadhyamam", 57, {"S", "R2", "G2", "M2", "P", "D1", "N3", "S."}, {"S.", "N3", "D1", "P", "M2", "G2", "R2", "S"}, {2, 1, 3, 1, 1, 3, 1}, {1, 3, 1, 1, 3, 1, 2} },
    { "Hemavathi", 58, {"S", "R2", "G2", "M2", "P", "D2", "N2", "S."}, {"S.", "N2", "D2", "P", "M2", "G2", "R2", "S"}, {2, 1, 3, 1, 2, 1, 2}, {2, 1, 2, 1, 3, 1, 2} },
    { "Dharmavathi", 59, {"S", "R2", "G2", "M2", "P", "D2", "N3", "S."}, {"S.", "N3", "D2", "P", "M2", "G2", "R2", "S"}, {2, 1, 3, 1, 2, 2, 1}, {1, 2, 2, 1, 3, 1, 2} },
    { "Neethimathi", 60, {"S", "R2", "G2", "M2", "P", "D3", "N3", "S."}, {"S.", "N3", "D3", "P", "M2", "G2", "R2", "S"}, {2, 1, 3, 1, 3, 1, 1}, {1, 1, 3, 1, 3, 1, 2} },
    { "Kaanthaamani", 61, {"S", "R2", "G3", "M2", "P", "D1", "N1", "S."}, {"S.", "N1", "D1", "P", "M2", "G3", "R2", "S"}, {2, 2, 2, 1, 1, 1, 3}, {3, 1, 1, 1, 2, 2, 2} },
    { "Rishabhapriya", 62, {"S", "R2", "G3", "M2", "P", "D1", "N2", "S."}, {"S.", "N2", "D1", "P", "M2", "G3", "R2", "S"}, {2, 2, 2, 1, 1, 2, 2}, {2, 2, 1, 1, 2, 2, 2} },
    { "Lathaangi", 63, {"S", "R2", "G3", "M2", "P", "D1", "N3", "S."}, {"S.", "N3", "D1", "P", "M2", "G3", "R2", "S"}, {2, 2, 2, 1, 1, 3, 1}, {1, 3, 1, 1, 2, 2, 2} },
    { "Vaachaspathi", 64, {"S", "R2", "G3", "M2", "P", "D2", "N2", "S."}, {"S.", "N2", "D2", "P", "M2", "G3", "R2", "S"}, {2, 2, 2, 1, 2, 1, 2}, {2, 1, 2, 1, 2, 2, 2} },
    { "Mechakalyaani", 65, {"S", "R2", "G3", "M2", "P", "D2", "N3", "S."}, {"S.", "N3", "D2", "P", "M2", "G3", "R2", "S"}, {2, 2, 2, 1, 2, 2, 1}, {1, 2, 2, 1, 2, 2, 2} },
    { "Chitraambari", 66, {"S", "R2", "G3", "M2", "P", "D3", "N3", "S."}, {"S.", "N3", "D3", "P", "M2", "G3", "R2", "S"}, {2, 2, 2, 1, 3, 1, 1}, {1, 1, 3, 1, 2, 2, 2} },
    { "Sucharitra", 67, {"S", "R3", "G3", "M2", "P", "D1", "N1", "S."}, {"S.", "N1", "D1", "P", "M2", "G3", "R3", "S"}, {3, 1, 2, 1, 1, 1, 3}, {3, 1, 1, 1, 2, 1, 3} },
    { "Jyothiswaroopini", 68, {"S", "R3", "G3", "M2", "P", "D1", "N2", "S."}, {"S.", "N2", "D1", "P", "M2", "G3", "R3", "S"}, {3, 1, 2, 1, 1, 2, 2}, {2, 2, 1, 1, 2, 1, 3} },
    { "Dhaatuvardhani", 69, {"S", "R3", "G3", "M2", "P", "D1", "N3", "S."}, {"S.", "N3", "D1", "P", "M2", "G3", "R3", "S"}, {3, 1, 2, 1, 1, 3, 1}, {1, 3, 1, 1, 2, 1, 3} },
    { "Naasikabhooshhani", 70, {"S", "R3", "G3", "M2", "P", "D2", "N2", "S."}, {"S.", "N2", "D2", "P", "M2", "G3", "R3", "S"}, {3, 1, 2, 1, 2, 1, 2}, {2, 1, 2, 1, 2, 1, 3} },
    { "Kosalam", 71, {"S", "R3", "G3", "M2", "P", "D2", "N3", "S."}, {"S.", "N3", "D2", "P", "M2", "G3", "R3", "S"}, {3, 1, 2, 1, 2, 2, 1}, {1, 2, 2, 1, 2, 1, 3} },
    { "Rasikapriya", 72, {"S", "R3", "G3", "M2", "P", "D3", "N3", "S."}, {"S.", "N3", "D3", "P", "M2", "G3", "R3", "S"}, {3, 1, 2, 1, 3, 1, 1}, {1, 1, 3, 1, 2, 1, 3} }
};