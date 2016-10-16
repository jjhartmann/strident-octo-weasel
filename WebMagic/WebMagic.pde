import java.util.Comparator;

int POINT_COUNT = 30;

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
}

void drawToMouse() {
  float eMax = sqrt(pow(width, 2) + pow(height, 2)); //<>//
  for (PVector p : points) {
    float eDist = sqrt(pow(mouseX - p.x, 2) + pow(mouseY - p.y, 2));
    println(eDist);
    println(log(10000000 * eMax/eDist));
    stroke(0, 0, 0, eMax/eDist);
    line(mouseX, mouseY, p.x, p.y);
    
  }
}