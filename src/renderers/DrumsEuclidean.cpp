#include "DrumsEuclidean.h"

/*
def self.distribute(pulses, steps)
  pauses = steps - pulses
  per_pulse = (pauses / pulses).to_i
  remainder = pauses % pulses

  rhythm = []
  pulses.times do |pulse|
    rhythm << 1
    per_pulse.times { rhythm << 0 }
    rhythm << 0 if pulse < remainder
  end

  return rhythm
end
*/

int *DrumsEuclidean::distribute(int pulses, int steps) {
	int *rhythm=new int[steps];
	int c_rhythm=0;

	int pauses = steps - pulses;
	int per_pulse = (pauses / pulses);
	int remainder = pauses % pulses;
//	printf("pulses %d, steps %d, per pulse %d, remainder %d\n",pulses, steps,per_pulse,remainder);

	for(int pulse=0;pulse < pulses;pulse++) {
		rhythm[c_rhythm]=1;
		c_rhythm++;
		for(int p=0;p<per_pulse;p++) {
			rhythm[c_rhythm]=0;
			c_rhythm++;
		}
		
		if(pulse < remainder) {
			rhythm[c_rhythm]=0;
			c_rhythm++;
		}
	}

/*	printf("c_rhythm %d\n",c_rhythm);

	for(int i=0;i<steps;i++) {
		printf("rhythm %d\n",rhythm[i]);
	}
*/
	return rhythm;
}


void DrumsEuclidean::render(RenderPart *p) {
	int pulses=p->getParam(RenderEvent::PULSES);
	int pitch=p->getParam(RenderEvent::PITCH);
	int psteps=p->getParam(RenderEvent::STEPS);
	int metrum=p->getParam(RenderEvent::METRUM);
	int vol=p->getParam(RenderEvent::VOL);

//	int steps=16;

	int steps=(p->getEndBar()-p->getStartBar())*p->getUniquePart()->getMetrum();

	double step=1.0/(double)metrum;

//	printf("step %d %d/%d %f\n",pulses,psteps,steps,step);
//	pulses=(int)((double)pulses/psteps * steps);
//	if(pulses < 1)
//		pulses=1;

	int c_step=0;
	int *rhythm=distribute(pulses,psteps);

//	double step=1.0;



//printf("%d-%d\n",p->getStartBar(), p->getEndBar());
  for (int i = p->getStartBar(); i < p->getEndBar(); ++i ) {
    for (double m = 0; m < p->getUniquePart()->getMetrum(); m += step) {
//    	printf("%d %d %f %d\n",c_step,rhythm[c_step],step,p->getUniquePart()->getMetrum());
    	if(rhythm[c_step % psteps]==1)
	        p->addPercNote(this->createTime(i, m), this->createTime(i, m + 0.1), pitch, vol);

    		c_step++;

	    }	
	}

//	printf("%f \n",c_step*step);

	delete rhythm;
 }
