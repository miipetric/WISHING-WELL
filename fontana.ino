#include <DmxSimple.h>   
#include <SPI.h>         
#include <SdFat.h>       
#include <SdFatUtil.h>   
#include <SFEMP3Shield.h>

#include <SFEMP3ShieldConfig.h>
#include <SFEMP3Shieldmainpage.h>


SdFat sd;                
SFEMP3Shield MP3player;  
 
#define SENSOR_PIN A1     
#define MIN_DELAY  10     

boolean senzor_on;
boolean sensorState;      
int animation_cycle;
//int animation_cycle2;
int scene_switcher;
unsigned long previousMillis = 0; 


typedef struct status_reflektora { 
  int red;
  int green;
  int blue;
} status_reflektora;

typedef struct status_animacije { 
  status_reflektora ref1; 
  status_reflektora ref2; 
} status_animacije;

// --- 1(dodati prototip) 
//scena1
void animation1(status_animacije *state); 
void animation2(status_animacije *state);
void animation3(status_animacije *state);
void animation4(status_animacije *state);
void animation5(status_animacije *state);
//scena2
void animation6(status_animacije *state); 
void animation7(status_animacije *state);
void animation8(status_animacije *state);
void animation9(status_animacije *state);
void animation10(status_animacije *state);
//scena3
void animation11(status_animacije *state); 
void animation12(status_animacije *state);
void animation13(status_animacije *state);
void animation14(status_animacije *state);
void animation15(status_animacije *state);
//scena4
void animation16(status_animacije *state); 
void animation17(status_animacije *state);
void animation18(status_animacije *state);
void animation19(status_animacije *state);
void animation20(status_animacije *state);


// --- 2) definicija
// status_animacije animationX_state;
//scena1
status_animacije animation1_state;
status_animacije animation2_state;
status_animacije animation3_state;
status_animacije animation4_state; 
status_animacije animation5_state; 
//scena2
status_animacije animation6_state;
status_animacije animation7_state;
status_animacije animation8_state;
status_animacije animation9_state; 
status_animacije animation10_state; 
//scena3
status_animacije animation11_state;
status_animacije animation12_state;
status_animacije animation13_state;
status_animacije animation14_state; 
status_animacije animation15_state; 
//scena4
status_animacije animation16_state;
status_animacije animation17_state;
status_animacije animation18_state;
status_animacije animation19_state; 
status_animacije animation20_state; 

void setup() {
  
  pinMode(SENSOR_PIN, INPUT); 
  animation_cycle = 0; 
  //animation_cycle2 = 0;
  scene_switcher = 1;

  // --- 3) alokacija memorije
  //scena1
  memset(&animation1_state, 0, sizeof(status_animacije));
  memset(&animation2_state, 0, sizeof(status_animacije));
  memset(&animation3_state, 0, sizeof(status_animacije));
  memset(&animation4_state, 0, sizeof(status_animacije));
  memset(&animation5_state, 0, sizeof(status_animacije));
  //scena2
  memset(&animation6_state, 0, sizeof(status_animacije));
  memset(&animation7_state, 0, sizeof(status_animacije));
  memset(&animation8_state, 0, sizeof(status_animacije));
  memset(&animation9_state, 0, sizeof(status_animacije));
  memset(&animation10_state, 0, sizeof(status_animacije));
  //scena3
  memset(&animation11_state, 0, sizeof(status_animacije));
  memset(&animation12_state, 0, sizeof(status_animacije));
  memset(&animation13_state, 0, sizeof(status_animacije));
  memset(&animation14_state, 0, sizeof(status_animacije));
  memset(&animation15_state, 0, sizeof(status_animacije));
  //scena4
  memset(&animation16_state, 0, sizeof(status_animacije));
  memset(&animation17_state, 0, sizeof(status_animacije));
  memset(&animation18_state, 0, sizeof(status_animacije));
  memset(&animation19_state, 0, sizeof(status_animacije));
  memset(&animation20_state, 0, sizeof(status_animacije));

  sd.begin(SD_SEL, SPI_HALF_SPEED);
  MP3player.begin();
}

void loop() {
  sensorState = digitalRead(SENSOR_PIN); 
  
  if ( sensorState == LOW){
    senzor_on = true;
  }
  if ( senzor_on == true) {
    unsigned long currentMillis = millis();
    
    if (currentMillis - previousMillis >= MIN_DELAY) {
      
      previousMillis = currentMillis;  

      switch (scene_switcher) {
        
        case 1:
          scena_1();
          break;  
        case 2:
          scena_2();
          break;
        case 3:
          scena_3();
          break;
        case 4:
          scena_4();
          break;
     }
    }
 
} 
  if (senzor_on == false) {
    
    animation_cycle = 0;
    //animation_cycle2 = 0;
    mrak();
    //delay(10000);
  }
}
// SCENE
void scena_1(){
  switch (animation_cycle) {
        
        case 0:
          start_delay();
          break;
        case 1:
          animation1(&animation1_state);
          break;
        case 2:
          animation2(&animation2_state);
          break;
        case 3:
          animation3(&animation3_state);
          break;
        case 4:
          animation4(&animation4_state);
          break;
        case 5:
          animation5(&animation5_state);
          break;
        }
}

void scena_2(){
  switch (animation_cycle) {
        
        case 0:
          start_delay();
          break;
        case 1:
          animation6(&animation6_state);
          break;
        case 2:
          animation7(&animation7_state);
          break;
        case 3:
          animation8(&animation8_state);
          break;
        case 4:
          animation9(&animation9_state);
          break;
        case 5:
          animation10(&animation10_state);
          break;
        }
}

void scena_3(){
  switch (animation_cycle) {
        
        case 0:
          start_delay();
          break;
        case 1:
          animation11(&animation11_state);
          break;
        case 2:
          animation12(&animation12_state);
          break;
        case 3:
          animation13(&animation13_state);
          break;
        case 4:
          animation14(&animation14_state);
          break;
        case 5:
          animation15(&animation15_state);
          break;
         }
}

void scena_4(){
  switch (animation_cycle) {
        
        case 0:
         start_delay();
         break;
        case 1:
          animation16(&animation16_state);
          break;
        case 2:
          animation17(&animation17_state);
          break;
        case 3:
          animation18(&animation18_state);
          break;
        case 4:
          animation19(&animation19_state);
          break;
        case 5:
          animation20(&animation20_state);
          break;
       }
}
//SCENA1_parts
void animation1(status_animacije *state) {

  reflektor_1(state->ref1.red, state->ref1.green, state->ref1.blue); // za refl1 spremat ce tu stanje za red, green i blue.. 
  reflektor_2(state->ref2.red, state->ref2.green, state->ref2.blue); // za refl2 spremat ce tu stanje za red, green i blue.. 

  state->ref1.red = 254;
  state->ref1.green = 254;
  state->ref1.blue = 254; 
  state->ref2.red = 254;
  state->ref2.green = 254;
  state->ref2.blue = 254; 
  
  state->ref1.red +=1;
  state->ref1.green +=1;
  state->ref1.blue +=1; 
  state->ref2.red +=1;
  state->ref2.green +=1;
  state->ref2.blue +=1; 
  
  

  if (state->ref1.red >= 255 && state->ref1.green >= 255 && state->ref1.blue >= 255 && state->ref2.red >= 255 && state->ref2.green >= 255 && state->ref2.blue >= 255) { // tu postavljamo do kuda koja boja ide maximalno (255, 185, bla bla bla whatever)
   
    animation2_state = *state; 
    ++animation_cycle;
  }
}

void animation2(status_animacije *state) {

  reflektor_1(state->ref1.red, state->ref1.green, state->ref1.blue);
  reflektor_2(state->ref2.red, state->ref2.green, state->ref2.blue);

  state->ref1.blue -= 1;
  state->ref1.red -= 1;

  state->ref2.green -= 1;
  state->ref2.red -= 1;

  if (
    (state->ref1.blue <= 0 && state->ref1.red <= 0) &&
    (state->ref2.green <= 0 && state->ref2.red <= 0)
  ) {
    animation3_state = *state;
    ++animation_cycle;
  }
}

void animation3(status_animacije *state) {

  reflektor_1(state->ref1.red, state->ref1.green, state->ref1.blue);
  reflektor_2(state->ref2.red, state->ref2.green, state->ref2.blue);

  state->ref1.green -= 1;
  state->ref1.blue += 1;
  
  state->ref2.green += 1;
  state->ref2.blue -= 1;
  
  if (state->ref1.blue >= 255 || state->ref2.green >=255) {
    animation4_state = *state;
    ++animation_cycle;
  }
}
// --- 4) ( dodat ponasanje ciklusa, tj komnada scene)
void animation4(status_animacije *state) {

  reflektor_1(state->ref1.red, state->ref1.green, state->ref1.blue);
  reflektor_2(state->ref2.red, state->ref2.green, state->ref2.blue);

  state->ref2.green -= 1;
  state->ref2.blue += 1;

  if (state->ref2.blue >= 255 || state->ref2.green <= 0) {
    
    animation5_state = *state;
    ++animation_cycle;
  }
}
void animation5(status_animacije *state) {

  reflektor_1(state->ref1.red, state->ref1.green, state->ref1.blue);
  reflektor_2(state->ref2.red, state->ref2.green, state->ref2.blue);

  state->ref1.red += 1;
  state->ref1.green += 1;
  state->ref2.red += 1;
  state->ref2.green += 1;

  if (state->ref1.red >= 255 || state->ref2.red >= 255) {
    senzor_on=false;
    ++scene_switcher;
    ++animation_cycle;
    delay(20000);
  }
  
}

//SCENA2_parts

void animation6(status_animacije *state) {

  reflektor_1(state->ref1.red, state->ref1.green, state->ref1.blue); // za refl1 spremat ce tu stanje za red, green i blue.. 
  reflektor_2(state->ref2.red, state->ref2.green, state->ref2.blue); // za refl2 spremat ce tu stanje za red, green i blue.. 

  state->ref1.red = 254;
  state->ref1.green = 254;
  state->ref1.blue = 254; 
  state->ref2.red = 254;
  state->ref2.green = 254;
  state->ref2.blue = 254; 
  
  state->ref1.red +=1;
  state->ref1.green +=1;
  state->ref1.blue +=1; 
  state->ref2.red +=1;
  state->ref2.green +=1;
  state->ref2.blue +=1; 
  
  

  if (state->ref1.red >= 255 && state->ref1.green >= 255 && state->ref1.blue >= 255 && state->ref2.red >= 255 && state->ref2.green >= 255 && state->ref2.blue >= 255) { // tu postavljamo do kuda koja boja ide maximalno (255, 185, bla bla bla whatever)
   
    animation7_state = *state; 
    ++animation_cycle;
  }
}

void animation7(status_animacije *state) {

  reflektor_1(state->ref1.red, state->ref1.green, state->ref1.blue);
  reflektor_2(state->ref2.red, state->ref2.green, state->ref2.blue);

  state->ref1.blue -= 1;
  state->ref1.green -= 1;

  state->ref2.blue -= 1;

  if ( state->ref1.blue <= 0 && state->ref1.green <= 0 && state->ref2.blue <= 0 ) {
    animation8_state = *state;
    ++animation_cycle;
  }
}

void animation8(status_animacije *state) {

  reflektor_1(state->ref1.red, state->ref1.green, state->ref1.blue);
  reflektor_2(state->ref2.red, state->ref2.green, state->ref2.blue);

  state->ref1.green += 1;
    
  state->ref2.green -= 1;
  
  if (state->ref1.green >= 255 || state->ref2.green <= 0) {
    animation9_state = *state;
    ++animation_cycle;
  }
}

// --- 4) ( dodat ponasanje ciklusa, tj komnada scene)
void animation9(status_animacije *state) {

  reflektor_1(state->ref1.red, state->ref1.green, state->ref1.blue);
  reflektor_2(state->ref2.red, state->ref2.green, state->ref2.blue);

  state->ref1.green -= 2;
 
  if (state->ref1.green <= 0 ) {
    
    animation10_state = *state;
    ++animation_cycle;
  }
  
}

void animation10(status_animacije *state) {

  reflektor_1(state->ref1.red, state->ref1.green, state->ref1.blue);
  reflektor_2(state->ref2.red, state->ref2.green, state->ref2.blue);

  state->ref1.green += 1;
  state->ref1.blue += 1;
  state->ref2.green += 1;
  state->ref2.blue += 1;

  if (state->ref1.green >= 255 || state->ref2.green >= 255 || state->ref1.blue >= 255 || state->ref2.blue >= 255) {
    senzor_on=false;
    ++scene_switcher;
    ++animation_cycle;
    delay(20000);
  }
  
}

//SCENA3_parts
void animation11(status_animacije *state) {

  reflektor_1(state->ref1.red, state->ref1.green, state->ref1.blue); // za refl1 spremat ce tu stanje za red, green i blue.. 
  reflektor_2(state->ref2.red, state->ref2.green, state->ref2.blue); // za refl2 spremat ce tu stanje za red, green i blue.. 

  state->ref1.red = 255;
  state->ref1.green = 255;
  state->ref1.blue = 255; 
  state->ref2.red = 255;
  state->ref2.green = 255;
  state->ref2.blue = 255; 
  
  

  state->ref1.red = 254;
  state->ref1.green = 254;
  state->ref1.blue = 254; 
  state->ref2.red = 254;
  state->ref2.green = 254;
  state->ref2.blue = 254; 
  
  state->ref1.red +=1;
  state->ref1.green +=1;
  state->ref1.blue +=1; 
  state->ref2.red +=1;
  state->ref2.green +=1;
  state->ref2.blue +=1; 
  
  

  if (state->ref1.red >= 255 && state->ref1.green >= 255 && state->ref1.blue >= 255 && state->ref2.red >= 255 && state->ref2.green >= 255 && state->ref2.blue >= 255) {
    animation12_state = *state; // kada kodje do kraja, sprema u "state" zadnje vrijednosti r g i b, i prelazi na slj ciklus, koji ce onda sa "*state" ucitat "di je stao"
    ++animation_cycle; // kada dodje do kraja povecaj animation_cycle za 1 (o switch-u gore onda prelazi na case 2 i tako dalje za svaki)
  } 
}

void animation12(status_animacije *state) {

  reflektor_1(state->ref1.red, state->ref1.green, state->ref1.blue);
  reflektor_2(state->ref2.red, state->ref2.green, state->ref2.blue);

  state->ref1.green -= 1;

  state->ref2.green -= 1;

  if ( state->ref1.green <= 0 && state->ref2.green <= 0) {
    animation13_state = *state;
    ++animation_cycle;
  }
}

void animation13(status_animacije *state) {

  reflektor_1(state->ref1.red, state->ref1.green, state->ref1.blue);
  reflektor_2(state->ref2.red, state->ref2.green, state->ref2.blue);

  state->ref1.green += 1;
  state->ref1.red -= 1;
  state->ref1.blue -= 1;
    
  state->ref2.green += 1;
  state->ref2.red -= 1;
  state->ref2.blue -= 1;
  
  if (state->ref1.green >= 255 && state->ref2.green >= 255 && state->ref1.red <= 0 && state->ref2.red <= 0 && state->ref1.blue <= 0 && state->ref2.blue <= 0) {
    animation14_state = *state;
    ++animation_cycle;
  }
}

// --- 4) ( dodat ponasanje ciklusa, tj komnada scene)
void animation14(status_animacije *state) {

  reflektor_1(state->ref1.red, state->ref1.green, state->ref1.blue);
  reflektor_2(state->ref2.red, state->ref2.green, state->ref2.blue);

  state->ref1.red += 2;
  
  state->ref2.red += 2;
 
  if (state->ref1.red >= 255 && state->ref2.red >= 255 ) {
    
    animation15_state = *state;
    ++animation_cycle;
  }
  
}

void animation15(status_animacije *state) {

  reflektor_1(state->ref1.red, state->ref1.green, state->ref1.blue);
  reflektor_2(state->ref2.red, state->ref2.green, state->ref2.blue);
  
  state->ref1.blue += 2;
  state->ref2.blue += 2;

  if (state->ref1.blue >= 255 || state->ref2.blue >= 255) {
    senzor_on=false;
    ++scene_switcher;
    ++animation_cycle;
    delay(20000);
  }
  
}

//SCENE4_parts
void animation16(status_animacije *state) {

  reflektor_1(state->ref1.red, state->ref1.green, state->ref1.blue); // za refl1 spremat ce tu stanje za red, green i blue.. 
  reflektor_2(state->ref2.red, state->ref2.green, state->ref2.blue); // za refl2 spremat ce tu stanje za red, green i blue.. 

  state->ref1.red = 254;
  state->ref1.green = 254;
  state->ref1.blue = 254; 
  state->ref2.red = 254;
  state->ref2.green = 254;
  state->ref2.blue = 254; 
  
  state->ref1.red +=1;
  state->ref1.green +=1;
  state->ref1.blue +=1; 
  state->ref2.red +=1;
  state->ref2.green +=1;
  state->ref2.blue +=1; 
  
  

  if (state->ref1.red >= 255 && state->ref1.green >= 255 && state->ref1.blue >= 255 && state->ref2.red >= 255 && state->ref2.green >= 255 && state->ref2.blue >= 255) { // tu postavljamo do kuda koja boja ide maximalno (255, 185, bla bla bla whatever)
    animation17_state = *state; // kada kodje do kraja, sprema u "state" zadnje vrijednosti r g i b, i prelazi na slj ciklus, koji ce onda sa "*state" ucitat "di je stao"
    ++animation_cycle; // kada dodje do kraja povecaj animation_cycle za 1 (o switch-u gore onda prelazi na case 2 i tako dalje za svaki)
  } 
}

void animation17(status_animacije *state) {

  reflektor_1(state->ref1.red, state->ref1.green, state->ref1.blue);
  reflektor_2(state->ref2.red, state->ref2.green, state->ref2.blue);

  state->ref1.red -= 1;
  state->ref1.green -= 1;

  state->ref2.red -= 1;
  state->ref2.green -= 1;
  state->ref2.blue -= 1;

  if ( state->ref1.red <= 0 && state->ref1.green <= 0 && state->ref2.red <= 0 && state->ref2.green  <= 0 && state->ref2.blue <= 0 ) {
    animation18_state = *state;
    ++animation_cycle;
  }
}

void animation18(status_animacije *state) {

  reflektor_1(state->ref1.red, state->ref1.green, state->ref1.blue);
  reflektor_2(state->ref2.red, state->ref2.green, state->ref2.blue);

  state->ref1.blue -= 1;
    
  state->ref2.blue += 1;
  
  if (state->ref1.blue <= 0 || state->ref2.blue >= 255) {
    animation19_state = *state;
    ++animation_cycle;
  }
}

// --- 4) ( dodat ponasanje ciklusa, tj komnada scene)
void animation19(status_animacije *state) {

  reflektor_1(state->ref1.red, state->ref1.green, state->ref1.blue);
  reflektor_2(state->ref2.red, state->ref2.green, state->ref2.blue);

  state->ref1.green += 1;
  
  state->ref2.blue -= 1;
  state->ref2.green += 1;
 
  if (state->ref1.green >= 255 || state->ref2.blue <= 0 || state->ref2.green >= 255 ) {
    
    animation20_state = *state;
    ++animation_cycle;
  }
  
}

void animation20(status_animacije *state) {

  reflektor_1(state->ref1.red, state->ref1.green, state->ref1.blue);
  reflektor_2(state->ref2.red, state->ref2.green, state->ref2.blue);

  state->ref1.red += 1;
  state->ref1.blue += 1;
  state->ref2.red += 1;
  state->ref2.blue += 1;

  if (state->ref1.red >= 255 || state->ref2.red >= 255 || state->ref1.blue >= 255 || state->ref2.blue >= 255) {
    senzor_on=false;
    scene_switcher = 1;
    ++animation_cycle;
    delay(20000);
  }
  
}

void reflektor_1(int r, int g, int b) {
  if (r > 255) r = 255;
  if (g > 255) g = 255;
  if (b > 255) b = 255;

  if (r < 0) r = 0;
  if (g < 0) g = 0;
  if (b < 0) b = 0;

  DmxSimple.write(1, r); 
  DmxSimple.write(2, g);
  DmxSimple.write(3, b);
  DmxSimple.write(4, 0);
}

void reflektor_2(int r, int g, int b) {
  if (r > 255) r = 255;
  if (g > 255) g = 255;
  if (b > 255) b = 255;

  if (r < 0) r = 0;
  if (g < 0) g = 0;
  if (b < 0) b = 0;

  DmxSimple.write(10, r); 
  DmxSimple.write(11, g);
  DmxSimple.write(12, b);
  DmxSimple.write(13, 0);
}

void mrak() { //mrak funkcija kojom cemo sa sigurnoscu drzati mrak na svim reflektorima
  reflektor_1(255, 255, 255); //000
  reflektor_2(255, 255, 255);

  memset(&animation1_state, 0, sizeof(status_animacije));
  memset(&animation2_state, 0, sizeof(status_animacije));
  memset(&animation3_state, 0, sizeof(status_animacije));
  memset(&animation4_state, 0, sizeof(status_animacije));
  memset(&animation5_state, 0, sizeof(status_animacije));//3) resetiranje vrij*/
  
  memset(&animation6_state, 0, sizeof(status_animacije));
  memset(&animation7_state, 0, sizeof(status_animacije));
  memset(&animation8_state, 0, sizeof(status_animacije));
  memset(&animation9_state, 0, sizeof(status_animacije));
  memset(&animation10_state, 0, sizeof(status_animacije));

  memset(&animation11_state, 0, sizeof(status_animacije));
  memset(&animation12_state, 0, sizeof(status_animacije));
  memset(&animation13_state, 0, sizeof(status_animacije));
  memset(&animation14_state, 0, sizeof(status_animacije));
  memset(&animation15_state, 0, sizeof(status_animacije));

  memset(&animation16_state, 0, sizeof(status_animacije));
  memset(&animation17_state, 0, sizeof(status_animacije));
  memset(&animation18_state, 0, sizeof(status_animacije));
  memset(&animation19_state, 0, sizeof(status_animacije));
  memset(&animation20_state, 0, sizeof(status_animacije));
  
}

void start_delay(){
  mrak();
  delay(2000);
  MP3player.playTrack(1);
  ++animation_cycle;
}

/*void end_delay(){
  senzor_on = false;
  delay(1000);
}*/
