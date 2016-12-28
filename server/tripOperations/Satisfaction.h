//
// Satisfaction.
//

#ifndef EX1_SATISFACTION_H
#define EX1_SATISFACTION_H


class Satisfaction {
private:
    int amount;
    double average;
public:
    Satisfaction();

    Satisfaction(Satisfaction *s);

    double getAverage() const;

    void update(int grade);
};


#endif //EX1_SATISFACTION_H
