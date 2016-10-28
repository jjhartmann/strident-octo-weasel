import java.util.Comparator;
PFont mono;
int POINT_COUNT = 400;

ArrayList<PVector> pointsX;
ArrayList<PVector> pointsY;

boolean doShift = false;
boolean invert = false;

void setup() {
 fullScreen(); 
 pointsX = new ArrayList<PVector>(POINT_COUNT);
 for (int i = 0; i < POINT_COUNT; ++i) {
   pointsX.add(new PVector());
 }
 
 mono = createFont("Neue Helvetica", 300);
 
 createRandPointSet();
}


void draw() {
  if (invert){
    background(255);
  } else {
    background(0);
  }
  // Draw Points
  drawPoints();
  drawToMouse();
  
  fill(255, 255, 255, 200);
  textSize(500);
  textAlign(CENTER);
  textFont(mono);
  text("CS 105", width/2, height/2 + 100);
  
  if (doShift){
    shift(2); 
  }
}

// Create random point set
void createRandPointSet() {
  for(PVector p : pointsX){
    int x = round(random(width));
    int y = round(random(height));
    p.x = x;
    p.y = y;
  }
  pointsX.sort(new comparePVecX()); //<>//
  pointsY = (ArrayList<PVector>)pointsX.clone();
  pointsY.sort(new comparePVecY());
}

// Shift all points
void shift(float i) {
   for(PVector p : pointsX){
    p.x += random(-i, i);
    p.y += random(-i, i);
  }
  pointsX.sort(new comparePVecX());
  pointsY = (ArrayList<PVector>)pointsX.clone();
  pointsY.sort(new comparePVecY());
}

// Draw the points
void drawPoints() {
  for (PVector p : pointsX) {
    noStroke();
    fill(220);
    ellipse(p.x, p.y, 5, 5);
  }
  
  drawWeb(pointsX);
  drawWeb(pointsY);
}



void drawWeb(ArrayList<PVector> list) {
  int offset = 0;
  for (int i = 0; i < list.size(); ++i){
    offset = (offset + 1) % 10;
    for (int j = i - offset; j < i + (20 - offset); ++j) {
      if (j >= 0 && j < list.size() && ecludianDistance(list.get(i), list.get(j)) < 100){
        drawDynamicLine(list.get(i), list.get(j));
      }
    }
  }
}

void drawToMouse() {
  float eMax = sqrt(pow(width, 2) + pow(height, 2)); //<>//
  for (PVector p : pointsX) {
    drawDynamicLine(new PVector(mouseX, mouseY), p);
  }
}

float ecludianDistance(PVector p1, PVector p2) {
 return  sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2)); 
}

void drawDynamicLine(PVector p1, PVector p2) {  
    float eDist = ecludianDistance(p1, p2) + 2;
    float decay = 20000/eDist - 90;
    
    if (invert) {
      stroke(0, 0, 0, decay);
    } else {
      stroke(255, 255, 255, decay);
    }
    float weight = constrain(map(decay, 0, 500, 0, 4), 0, 4);
    //println(weight);
    strokeWeight(((weight >= 0) ? weight : 0));
    line(p1.x, p1.y, p2.x, p2.y);
}

// Comparator
class comparePVecX implements Comparator<PVector> {
   public int compare(PVector p, PVector v) {
     if (p.x < v.x) {
       return -1;
     } else if (p.x > v.x) {
       return 1;
     }
     return 0;
   }
}
class comparePVecY implements Comparator<PVector> {
   public int compare(PVector p, PVector v) {
     if (p.y < v.y) {
       return -1;
     } else if (p.y > v.y) {
       return 1;
     }
     return 0;
   }
}

void keyPressed() {
 if (key == 'r') {
   createRandPointSet();
 }
 if (key == 's') {
   if (doShift) {
     doShift = false;
   } else {
     doShift = true;
   }
 }
 
 if (key == 'i') {
   if (invert){
     invert = false;
   } else {
     invert = true;
   } 
 }
 
}