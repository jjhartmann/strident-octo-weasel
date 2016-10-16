import java.util.Comparator; //<>// //<>// //<>//

ArrayList<PVector> pointSet;
ArrayList<PVector> pointSetCopy;

ArrayList<ArrayList<PVector>> hullSetU;
ArrayList<ArrayList<PVector>> hullSetL;

boolean drawHullU = false;
boolean drawHullL = false;

int POINT_SIZE = 20;

void setup() {
  size(800, 800);
  hullSetU = new ArrayList<ArrayList<PVector>>();
  hullSetL = new ArrayList<ArrayList<PVector>>();

  pointSet = new ArrayList<PVector>(POINT_SIZE);
  for (int i = 0; i < POINT_SIZE; ++i) {
    pointSet.add(new PVector());
  }

  createRandomPointSet();
}

void draw() {
  background(200);
  drawRandomPointSet();

  if (drawHullU) {
    drawConvexHullU();
  }
  if (drawHullL) {
    drawConvexHullL();
  }
}

void drawRandomPointSet() {
  noStroke();
  fill(0);
  for (int i = 0; i < pointSet.size(); ++i) {
    ellipse(pointSet.get(i).x, pointSet.get(i).y, 10, 10);
  }
}

void createRandomPointSet() {
  for (PVector p : pointSet) {
    float x = random(width);// (randomGaussian() * width/9) + width/2;
    float y = random(height);//(randomGaussian() * height/9) + height/2;
    p.x = round(x);
    p.y = round(y);
  }

  hullSetU.clear();
  hullSetL.clear();

  pointSet.sort(new SortByXCord());
  pointSetCopy = (ArrayList<PVector>)pointSet.clone();
  
  computeCH(pointSetCopy);
  
}


void computeCH(ArrayList<PVector> pSet) {

  int HIndex = 0;
  while (pSet.size() > 2) 
  {
    hullSetU.add(new ArrayList<PVector>());
    hullSetL.add(new ArrayList<PVector>());
    
    ArrayList<PVector> U = hullSetU.get(HIndex);
    ArrayList<PVector> L = hullSetL.get(HIndex);
    // Compute Hull
    computeConvexHullSet(pSet, U, L); 

    // Delete U Nodes from pSet
    
    for (int i = 0, j = 0; i < U.size() && j < pSet.size(); ++i) { //<>//
      while (j < pSet.size() && pSet.get(j).x < U.get(i).x) {
        ++j;
      }    
      if (j < pSet.size() && pSet.get(j) == U.get(i)) {
        pSet.remove(j);
      }
    }

    // Delete L Nodes
    for (int i = L.size() - 1, j = 0; i >= 0 && j < pSet.size(); --i) { //<>//
      while (j < pSet.size() && pSet.get(j).x < L.get(i).x) {
        ++j;
      }    
      if (j < pSet.size() && pSet.get(j) == L.get(i)) {
        pSet.remove(j);
      }
    }

    HIndex++;
  }
}


// Compute the convex Hull
void computeConvexHullSet(ArrayList<PVector> pSet, ArrayList<PVector> U, ArrayList<PVector> L) {
  // Sort Point Set
  int size = pSet.size();

  U.add(pSet.get(0));
  U.add(pSet.get(1));
  int j = U.size() -1;

  // Iterate through point set in order to build hull
  for (int i = 2; i < size; ++i) {
    U.add(pSet.get(i));
    ++j;

    while ( j >= 2 && checkCrossProduct(U.get(j), U.get(j - 1), U.get(j - 2))) {
      U.remove(j-1);  
      --j;
    }
  }

  // Iterate throw lower halve
  L.add(pSet.get(size - 1));
  L.add(pSet.get(size - 2));
  int k = L.size() - 1;

  for (int i = size - 1; i >= 0; --i) {
    L.add(pSet.get(i));
    ++k;

    while ( k >= 2 && checkCrossProduct(L.get(k), L.get(k - 1), L.get(k - 2))) {
      L.remove(k-1);  
      --k;
    }
  }
}

float dRes = 0;
// Calculate cross product and determine left turns (Positive Angle)
boolean checkCrossProduct(PVector p1, PVector p2, PVector p3) {
  dRes = ((p2.x - p1.x)*(p3.y - p1.y)) - ((p2.y - p1.y)*(p3.x - p1.x));
  return ((p2.x - p1.x)*(p3.y - p1.y)) - ((p2.y - p1.y)*(p3.x - p1.x)) >= 0;
}


// Draw Convex Hull
void drawConvexHullU() {
  int size = hullSetU.size();
  for (int j = 0; j < size; ++j) {
    ArrayList<PVector> pVec =  hullSetU.get(j);
    for (int i = 0; i < pVec.size() -1 ; ++i) {
      PVector b = pVec.get(i);
      PVector e = pVec.get(i + 1);
      stroke(0);
      line(b.x, b.y, e.x, e.y);
    }
  }
}
void drawConvexHullL() {
  int size = hullSetL.size();
  for (int j = 0; j < size; ++j) {
    ArrayList<PVector> pVec =  hullSetL.get(j);
    for (int i = 0; i < pVec.size() - 1; ++i) {
      PVector b = pVec.get(i);
      PVector e = pVec.get(i + 1);
      stroke(0);
      line(b.x, b.y, e.x, e.y);
    }
  }
}

void keyPressed() {
  if (key == 'r') {
    createRandomPointSet();
  }

  if (key == 'u') {
    if (drawHullU) {
      drawHullU = false;
    } else {
      drawHullU = true;
    }
  }

  if (key == 'l') {
    if (drawHullL) {
      drawHullL = false;
    } else {
      drawHullL = true;
    }
  }
}

class SortByXCord implements Comparator<PVector> {
  //@Override
  public int compare(PVector p1, PVector p2) {
    if (p1.x < p2.x) {
      return -1;
    } else if (p1.x > p2.x) {
      return 1;
    }

    return 0;
  }
}