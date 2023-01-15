# Class inheritance


## 1. Base and derived classes: 30 minutes *maximum*
### Part a.
Given the following classes:    
```cpp
  class Animal {
    public:
    virtual void make_noise() {}
    void eat() {}
    void sleep() {}
    void roam() {}
  };

  class Canine : public Animal {
    public:
    void roam() {}
    void eat() {}
  };


  class Wolf : public Canine {
    public:
    void make_noise() {}
    void eat() {}

  };
```

And given:    
```cpp
  void call (Animal& a) {
    a.make_noise();
    a.roam();
    a.eat();
    a.sleep();
  }

  int main () {
    Wolf w;
    call(w);
  }
```

Identify which of the versions of the methods called by `Wolf w` are invoked.

//Wolf::make_noise(), Canine::roam(), Wolf::eat(), Animal::sleep()


### Part b.
Given the following classes:

```
Musician
RockStar
MusicFan
BassPlayer
ConcertPianist
```

- Identify appropriate derived classes and base classes.

//Musician being a base class, all the others would be derived classes of musician with the exception of MusicFan which would be a dependency.


- Draw a class diagram that makes sense. 
  Consider the use of inheritance, composition, and dependency relations.

  Don't over engineer this diagram.
  Simple ASCII art like:

  ```
   BassClass <|-- DerivedClass // inheritance
   Car  *-- Engine             // composition
   Car  --  Driver             // dependency
  ```

  is sufficient.

//
```
BaseClass <|-- Musician
DerivedClasses *-- RockStar, BassPlayer, ConcertPianist
Dependency -- MusicFan
```
  
-  Explain why you chose the relationships you did.

//
I chose to make Musician the base class because it is the most general class, and the others are more specific. 
I chose to make BassPlayer a derived class of Musician because it is a type of musician. 
I chose to make ConcertPianist a derived class of Musician because it is a type of musician. 
I chose to make RockStar a derived class of Musician because it is a type of musician.
I chose to make MusicFan a dependency because it is not a type of musician, but a type of person who enjoys music of the other above classes.


### Part c.
Given the following classes:

```
  Bathtub     Bathroom     Bubbles     Sink
```

- Draw a class diagram that makes sense. 
  Consider the use of inheritance, composition, and dependency relations.

BaseClass <|-- Bathroom
DerivedClasses *-- Bathtub, Sink
Dependency -- Bubbles
  
- Explain why you chose the relationships you did.

I chose to make Bathroom the base class because it is the most general class, and the others are more specific.
I chose to make Bathtub a derived class of Bathroom because it is in the bathroom.
I chose to make Sink a derived class of Bathroom because it is in the bathroom.
I chose to make Bubbles a dependency because it is not in the bathroom, but it is in the bathtub and sink so it depends on them.

## 2. Inheritance Declarations
Identify the relationships that make sense.

If a relationship doesn't make sense, explain why.
For example:
```cpp
struct base : derived       // no. Relationship is backwards.
```

Complete the following:

```cpp
struct oven : kitchen       //makes sense as it is an item in the kitchen

struct guitar : instrument  //makes sense as it is a type of instrument

struct person : employee    //doesnt make sense as an employee is a type of person not the other way around
  
struct ferrari : engine     //doesnt make sense as a ferrari is more than just the engine and the engine is just a part of the ferrari

struct fried_egg : food      //makes sense as it is a type of food

struct beagle : pet        //makes sense as it is a type of pet

struct porch : house       //makes sense as it is a part of the house

struct metal : titanium    //does not make sense as titanium is a type of metal not the other way around

struct grateful_dead : band  //makes sense as the grateful_dead is a type of band
```


## 3. Abstract classes: 30 minutes *maximum*
Given the following classes and a main method that uses them:

```cpp
  class car {
    public:
    // insert A here
  };

  class race_car : public car {
    public:
    // insert B here
  };

  class electric_car : public car {
    public:
    bool accelerate(int change) const override {
      std::cout << "Shhhh...  " << change << std::endl;
      return true;
    }
  };

  int main () {
    vector<car*> cars(3);
    cars[0] = new race_car();
    cars[1] = new electric_car();
    cars[2] = new car();

    for (int x = 0; x < cars.size(); x++) {
      cars[x]->accelerate(x);
    }
    return 0;
  }
```

Examine each of the 4 pairs of code that follow and
describe what would happen when inserted at locations "A" and "B".
For **each pair**, answer **all** of the following:

- Which do not compile? 
- Which compile and produce the following output?

  ```
  Vroom! 0 
  Shhhh... 1 
  Change is: 2
  ```

- For those that compile,
  but do not produce the output above, **explain** why they do not.

### Pair #1:
**A:**  
```cpp
bool accelerate(int change) const {
  std::cout << "Change is: " << change << std::endl;
  return true;
}
```

**B:**  
```cpp
  bool accelerate(int change) const {
    std::cout << "Vroom!  " << change << std::endl;
    return false;
  }
```

//does not compile because accelerate is not a virtual function and cannot be overridden  


### Pair #2:
**A:**  
```cpp
virtual bool accelerate(int change) const {
  std::cout << "Change is: " << change << std::endl;
  return true;
}
```

**B:**  
```cpp
bool accelerate(int change) const {
  std::cout << "Vroom!  " << change << std::endl;
  return false;
}
```

//does compile and produces the output above because it is overriding the accelerate function in the base class car


### Pair #3:
**A:**  
```cpp
virtual bool accelerate(int change) const {
  std::cout << "Change is: " << change << std::endl;
  return true;
}
```

**B:**  
```cpp
bool accelerate(long change) const {
  std::cout << "Vroom!  " << change << std::endl;
  return false;
}
```

// does compile but doesnt produce the output above because it doesnt override the accelerate function in the base class car and and uses the original function instead when called

### Pair #4:
**A:**  
```cpp
virtual bool accelerate(int change) const {
  std::cout << "Change is: " << change << std::endl;
  return true;
}
```

**B:**  
```cpp
bool accelerate(long change) const override {
  std::cout << "Vroom!  " << change << std::endl;
  return false;
}
```

//does compile and produce the output above 


## Turnitin
- Add your new and modified files: `git add . . . `
- Save your changes: `git commit . . . `
- Submit your work for grading: `git push`

## Reflection
When you are done, take a moment to 
[rate this lab](https://forms.gle/BWyXbCPt3dwwpVom6).
