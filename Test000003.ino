  // https://www.youtube.com/c/ClaudeDufourmont
  // DFT_#A116 COMMENT FAIRE CLIGNOTER A BAS COUP DES CORDONS LUMINEUX

  //#define NUM_Rub 6  // Changer cette valeur selon les besoins (doit être <= 7) car ULN2003 comporte 7 transistors seulement (sinon ajouter un 2ème ULN2003)
  #define NUM_Rub 3

  //int BrochesRubans[NUM_Rub] = {D1, D2, D3, D4, D5, D6};
  int BrochesRubans[NUM_Rub] = {D1, D2, D3};

  // Temps de transition et d'allumage entre chaque étape en millisecondes
  unsigned long TempoTransition = 50;
  unsigned long TempoAllumage = 300;
  unsigned long offTime = TempoAllumage - TempoTransition;

  //**************************************************************************************************************************************************************
  byte intensityLEDs = 128;                       //ATTENTION LES CORDONS DE LEDS NE COMPORTENT DE RESISTANCE - DIMINUER LA TENSION MOYENNE AVEC UNE VALEUR <= 128
  //**************************************************************************************************************************************************************
  
  void setup() 
  {
  // Configuation des broches PWM de sortie
  for (int i = 0; i < NUM_Rub; ++i) 
  {
  pinMode(BrochesRubans[i], OUTPUT);
  }
  }

  void loop() 
  {
  for (int cord = 0; cord < NUM_Rub; ++cord) 
  {
  // Allumage du cordon actuel
  analogWrite(BrochesRubans[cord], intensityLEDs);
  delay(TempoTransition);
  // Extinction du cordon précédent
  if (cord > 0) 
  {
  analogWrite(BrochesRubans[cord - 1], 0);
  }
   delay(offTime);
  }
  // Extinction du dernier cordon
  analogWrite(BrochesRubans[NUM_Rub - 1], 0);
  delay(TempoTransition);
  }
