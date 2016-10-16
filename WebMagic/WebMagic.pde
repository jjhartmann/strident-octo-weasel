import java.util.Comparator;

int POINT_COUNT = 100;

ArrayList<PVector> points;


void setup() {
 size(800, 600); 
 points = new ArrayList<PVector>(POINT_COUNT);
 for (int i = 0; i < POINT_COUNT; ++i) {
   points.add(new PVector());
 }
 
 createRandPointSet();
}


void draw() {
  background(200);
  
  // Draw Points
  drawPoints();
  drawToMouse();
}

// Create random point set
void createRandPointSet() {
  for(PVector p : points){
    int x = round(random(width));
    int y = round(random(height));
    p.x = x;
    p.y = y;
  }
}

// Draw the points
void drawPoints() {
  for (PVector p : points) {
    noStroke();
    fill(80);
    ellipse(p.x, p.y, 5, 5);
  }
  
  // Draw Web
}

void drawToMouse() {
  float eMax = sqrt(pow(width, 2) + pow(height, 2)); //<>//
  for (PVector p : points) {
    drawDynamicLine(new PVector(mouseX, mouseY), p);
  }
}

void drawDynamicLine(PVector p1, PVector p2) {  
    float eDist = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
    float decay = 10000/eDist - 90;
    stroke(0, 0, 0, decay);
    
    float weight = constrain(map(decay, 0, 500, 0, 5), 0, 5);
    println(weight);
    strokeWeight(((weight >= 0) ? weight : 0));
    line(p1.x, p1.y, p2.x, p2.y);
}