/*
 * seven_segment.h
 *
 * Created: 3/25/2023 12:13:28 PM
 *  Author: dell
 */ 


#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_

#define SS1_PORT		(PORT_C)
#define SS1_COM_PORT	(PORT_D)
#define SS1_COM_PIN		(PIN0)

#define SS2_PORT		(PORT_C)
#define SS2_COM_PORT	(PORT_C)
#define SS2_COM_PIN		(PIN7)

#define SS_A	0
#define SS_B	1
#define SS_C	2
#define SS_D	3
#define SS_E	4
#define SS_F	5
#define SS_G	6



void seven_segment1_init(void);
void seven_segment2_init(void);

void seven_segment1_sendNum(uint8 num);
void seven_segment2_sendNum(uint8 num);

void seven_segment1_release(void);
void seven_segment2_release(void);








#endif /* SEVEN_SEGMENT_H_ */