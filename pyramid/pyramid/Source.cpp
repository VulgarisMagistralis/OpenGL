#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string.h>
#include <cstring>
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include "./tinyXML/tinyxml.h" 

int alpha = 0, beta = 0, r = 5;
#define POINT_COUNT 5
// Points that make up the loop for catmull-rom interpolation
float up[4] = { 0,1,0,0 };
using namespace std;
int lenght = 0;
float *sun;
float yc = 0;
float xc = 0;
float zc = 0;
float vc = 0;
float bc = 0;
float nc = 0;
float ks = 0;
struct rotatef
{
	float angle;
	float x;
	float y;
	float z;
};
struct orbit
{
	float total;
	float time;
	float point[5][3];
};
struct color
{
	float r;
	float g;
	float b;
};
struct translatef
{
	float x;
	float y;
	float z;
};
struct planet
{
	rotatef r;
	orbit or ;
	translatef t;
	color c;
	float s;
	float sm;
	char* fpath;
	planet *p;
};
planet solar;


void readsun(TiXmlElement* pElem) {
	pElem = pElem->FirstChildElement();
	pElem = pElem->FirstChildElement();
	pElem = pElem->FirstChildElement();
	TiXmlAttribute *atr = pElem->FirstAttribute();
	//rotate
	//angle
	char* pszAttrib = (char*)atr->Name();
	solar.r.angle = atof(atr->Value());
	printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.r.angle);
	atr = atr->Next();
	//x
	pszAttrib = (char*)atr->Name();
	solar.r.x = atof(atr->Value());
	printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.r.x);
	atr = atr->Next();
	//y
	pszAttrib = (char*)atr->Name();
	solar.r.y = atof(atr->Value());
	printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.r.y);
	atr = atr->Next();
	//z
	pszAttrib = (char*)atr->Name();
	solar.r.z = atof(atr->Value());
	printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.r.z);

	pElem = pElem->NextSiblingElement();
	atr = pElem->FirstAttribute();

	//scale
	//r
	pszAttrib = (char*)atr->Name();
	solar.s = atof(atr->Value());
	printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.s);

	pElem = pElem->NextSiblingElement();
	atr = pElem->FirstAttribute();
	//translatef
	//x
	pszAttrib = (char*)atr->Name();
	solar.t.x = atof(atr->Value());
	printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.t.x);
	atr = atr->Next();
	//y
	pszAttrib = (char*)atr->Name();
	solar.t.y = atof(atr->Value());
	printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.t.y);
	atr = atr->Next();
	//z
	pszAttrib = (char*)atr->Name();
	solar.t.z = atof(atr->Value());
	printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.t.z);

	pElem = pElem->NextSiblingElement();
	atr = pElem->FirstAttribute();
	//color
	//r
	pszAttrib = (char*)atr->Name();
	solar.c.r = atof(atr->Value());
	printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.c.r);
	atr = atr->Next();
	//g
	pszAttrib = (char*)atr->Name();
	solar.c.g = atof(atr->Value());
	printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.c.g);
	atr = atr->Next();
	//b
	pszAttrib = (char*)atr->Name();
	solar.c.b = atof(atr->Value());
	printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.c.b);
	//filepath
	pElem = pElem->NextSiblingElement();
	atr = pElem->FirstAttribute();
	solar.fpath = (char*)atr->Value();
	printf("------------Attribute: %s, Data: %s\n", pszAttrib, solar.fpath);
}
void readplanet(TiXmlElement* pElem, int n) {
	TiXmlElement *pcop;
	char* pszNode = (char*)pElem->Value();
	if (pszNode)
		printf("Node: %s\n", pszNode);
	pElem = pElem->FirstChildElement(); pszNode = (char*)pElem->Value(); printf("Node: %s\n", pszNode);
	pElem = pElem->FirstChildElement(); pszNode = (char*)pElem->Value(); printf("Node: %s\n", pszNode);
	for (size_t i = 0; i < n; i++)
	{
		pElem = pElem->NextSiblingElement(); pszNode = (char*)pElem->Value(); printf("Node: %s\n", pszNode);
	}
	pElem = pElem->FirstChildElement(); pszNode = (char*)pElem->Value(); printf("++++++++++++Node: %s\n", pszNode);
	pcop = pElem;
	pcop = pcop->FirstChildElement(); pszNode = (char*)pcop->Value(); printf("Node: %s\n", pszNode);
	TiXmlAttribute *atr = pcop->FirstAttribute();
	//orbit
	//time
	char*  pszAttrib = (char*)atr->Name();
	solar.p[n - 1]. or .time = atof(atr->Value());
	printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1]. or .time);
	atr = atr->Next();
	pcop = pcop->NextSiblingElement(); pszNode = (char*)pcop->Value(); printf("Node: %s\n", pszNode);
	atr = pcop->FirstAttribute();
	//x
	for (size_t i = 0; i < 5; i++)
	{
		pszAttrib = (char*)atr->Name();
		solar.p[n - 1]. or .point[i][0] = atof(atr->Value());
		//printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1]. or .x[i]);
		atr = atr->Next();
	}
	//y
	for (size_t i = 0; i < 5; i++)
	{
		pszAttrib = (char*)atr->Name();
		solar.p[n - 1]. or .point[i][1] = atof(atr->Value());
		//printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1]. or .y[i]);
		atr = atr->Next();
	}
	//z
	for (size_t i = 0; i < 5; i++)
	{
		pszAttrib = (char*)atr->Name();
		solar.p[n - 1]. or .point[i][2] = atof(atr->Value());
		//printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1]. or .z[i]);
		atr = atr->Next();
	}
	pElem = pElem->NextSiblingElement(); pszNode = (char*)pElem->Value(); printf("Node: %s\n", pszNode);
	pElem = pElem->FirstChildElement(); pszNode = (char*)pElem->Value(); printf("Node: %s\n", pszNode);
	atr = pElem->FirstAttribute();
	//rotate
	//angle
	pszAttrib = (char*)atr->Name();
	solar.p[n - 1].r.angle = atof(atr->Value());
	printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].r.angle);
	atr = atr->Next();
	//x
	pszAttrib = (char*)atr->Name();
	solar.p[n - 1].r.x = atof(atr->Value());
	printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].r.x);
	atr = atr->Next();
	//y
	pszAttrib = (char*)atr->Name();
	solar.p[n - 1].r.y = atof(atr->Value());
	printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].r.y);
	atr = atr->Next();
	//z
	pszAttrib = (char*)atr->Name();
	solar.p[n - 1].r.z = atof(atr->Value());
	printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].r.z);

	pElem = pElem->NextSiblingElement();
	atr = pElem->FirstAttribute();
	//scale
	//r
	pszAttrib = (char*)atr->Name();
	solar.p[n - 1].s = atof(atr->Value());
	printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].s);

	pElem = pElem->NextSiblingElement();
	atr = pElem->FirstAttribute();

	//translatef
	//x
	pszAttrib = (char*)atr->Name();
	solar.p[n - 1].t.x = atof(atr->Value());
	printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].t.x);
	atr = atr->Next();
	//y
	pszAttrib = (char*)atr->Name();
	solar.p[n - 1].t.y = atof(atr->Value());
	printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].t.y);
	atr = atr->Next();
	//z
	pszAttrib = (char*)atr->Name();
	solar.p[n - 1].t.z = atof(atr->Value());
	printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].t.z);

	pElem = pElem->NextSiblingElement();
	atr = pElem->FirstAttribute();
	//color
	//r
	pszAttrib = (char*)atr->Name();
	solar.p[n - 1].c.r = atof(atr->Value());
	printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].c.r);
	atr = atr->Next();
	//g
	pszAttrib = (char*)atr->Name();
	solar.p[n - 1].c.g = atof(atr->Value());
	printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].c.g);
	atr = atr->Next();
	//b
	pszAttrib = (char*)atr->Name();
	solar.p[n - 1].c.b = atof(atr->Value());
	printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].c.b);
	//filepath
	pElem = pElem->NextSiblingElement();
	atr = pElem->FirstAttribute();
	solar.p[n - 1].fpath = (char*)atr->Value();
	printf("------------Attribute: %s, Data: %s\n", pszAttrib, solar.p[n - 1].fpath);
}
void readplanetandother(TiXmlElement* pElem, int n, int ringc) {
	TiXmlElement *pcop;
	char* pszNode = (char*)pElem->Value();
	pElem = pElem->FirstChildElement();
	pElem = pElem->FirstChildElement(); pszNode = (char*)pElem->Value(); printf("Node: %s\n", pszNode);
	for (size_t i = 0; i < n; i++)
	{
		pElem = pElem->NextSiblingElement(); pszNode = (char*)pElem->Value(); printf("Node: %s\n", pszNode);
	}
	pElem = pElem->FirstChildElement(); pszNode = (char*)pElem->Value(); printf("++++Node: %s\n", pszNode);
	TiXmlElement* pElems = pElem;
	pcop = pElem;
	pcop = pcop->FirstChildElement(); pszNode = (char*)pcop->Value(); printf("494Node: %s\n", pszNode);
	TiXmlAttribute *atr = pcop->FirstAttribute();
	//orbit
	//time
	char*  pszAttrib = (char*)atr->Name();
	solar.p[n - 1]. or .time = atof(atr->Value());
	printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1]. or .time);
	atr = atr->Next();
	pcop = pcop->NextSiblingElement(); pszNode = (char*)pcop->Value(); printf("Node: %s\n", pszNode);
	atr = pcop->FirstAttribute();
	//x
	for (size_t i = 0; i < 5; i++)
	{
		pszAttrib = (char*)atr->Name();
		solar.p[n - 1]. or .point[i][0] = atof(atr->Value());
		//printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1]. or .x[i]);
		atr = atr->Next();
	}
	//y
	for (size_t i = 0; i < 5; i++)
	{
		pszAttrib = (char*)atr->Name();
		solar.p[n - 1]. or .point[i][1] = atof(atr->Value());
		//printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1]. or .y[i]);
		atr = atr->Next();
	}
	//z
	for (size_t i = 0; i < 5; i++)
	{
		pszAttrib = (char*)atr->Name();
		solar.p[n - 1]. or .point[i][2] = atof(atr->Value());
		//printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1]. or .z[i]);
		atr = atr->Next();
	}
	pElem = pElem->NextSiblingElement(); pszNode = (char*)pElem->Value(); printf("888Node: %s\n", pszNode);
	pElem = pElem->FirstChildElement(); pszNode = (char*)pElem->Value(); printf("9999Node: %s\n", pszNode);

	atr = pElem->FirstAttribute();
	//rotate
	//angle
	pszAttrib = (char*)atr->Name();
	solar.p[n - 1].r.angle = atof((char*)atr->Value());
	printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].r.angle);
	atr = atr->Next();
	//x
	pszAttrib = (char*)atr->Name();
	solar.p[n - 1].r.x = atof(atr->Value());
	printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].r.x);
	atr = atr->Next();
	//y
	pszAttrib = (char*)atr->Name();
	solar.p[n - 1].r.y = atof(atr->Value());
	printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].r.y);
	atr = atr->Next();
	//z
	pszAttrib = (char*)atr->Name();
	solar.p[n - 1].r.z = atof(atr->Value());
	printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].r.z);

	pElem = pElem->NextSiblingElement();
	atr = pElem->FirstAttribute();
	//scale
	//r
	pszAttrib = (char*)atr->Name();
	solar.p[n - 1].s = atof(atr->Value());
	printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].s);

	pElem = pElem->NextSiblingElement();
	atr = pElem->FirstAttribute();
	//translatef
	//x
	pszAttrib = (char*)atr->Name();
	solar.p[n - 1].t.x = atof(atr->Value());
	printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].t.x);
	atr = atr->Next();
	//y
	pszAttrib = (char*)atr->Name();
	solar.p[n - 1].t.y = atof(atr->Value());
	printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].t.y);
	atr = atr->Next();
	//z
	pszAttrib = (char*)atr->Name();
	solar.p[n - 1].t.z = atof(atr->Value());
	printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].t.z);

	pElem = pElem->NextSiblingElement();
	atr = pElem->FirstAttribute();
	//color
	//r
	pszAttrib = (char*)atr->Name();
	solar.p[n - 1].c.r = atof(atr->Value());
	printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].c.r);
	atr = atr->Next();
	//g
	pszAttrib = (char*)atr->Name();
	solar.p[n - 1].c.g = atof(atr->Value());
	printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].c.g);
	atr = atr->Next();
	//b
	pszAttrib = (char*)atr->Name();
	solar.p[n - 1].c.b = atof(atr->Value());
	printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].c.b);
	//filepath
	pElem = pElem->NextSiblingElement();
	atr = pElem->FirstAttribute();
	solar.p[n - 1].fpath = (char*)atr->Value();
	printf("------------Attribute: %s, Data: %s\n", pszAttrib, solar.p[n - 1].fpath);

	//moon
	pElems = pElems->NextSiblingElement(); pszNode = (char*)pElems->Value(); printf("Node: %s\n", pszNode);
	pElems = pElems->NextSiblingElement(); pszNode = (char*)pElems->Value(); printf("+-+-+-+Node:%s\n", pszNode);
	if (ringc == 1) {
		pElems = pElems->FirstChildElement(); pszNode = (char*)pElems->Value(); printf("+++Node: %s\n", pszNode);
		pcop = pElems;
		pcop = pcop->FirstChildElement();
		//orbit
		//time
		atr = pcop->FirstAttribute();
		pszAttrib = (char*)atr->Name();
		solar.p[n - 1]. or .time = atof(atr->Value());
		printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1]. or .time);
		atr = atr->Next();
		pcop = pcop->NextSiblingElement(); pszNode = (char*)pcop->Value(); printf("Node: %s\n", pszNode);
		atr = pcop->FirstAttribute();
		//x
		for (size_t i = 0; i < 5; i++)
		{
			pszAttrib = (char*)atr->Name();
			solar.p[n - 1].p[0]. or .point[i][0] = atof(atr->Value());
			//printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].p[0]. or .x[i]);
			atr = atr->Next();
		}
		//y
		for (size_t i = 0; i < 5; i++)
		{
			pszAttrib = (char*)atr->Name();
			solar.p[n - 1].p[0]. or .point[i][1] = atof(atr->Value());
			//printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].p[0]. or .y[i]);
			atr = atr->Next();
		}
		//z
		for (size_t i = 0; i < 5; i++)
		{
			pszAttrib = (char*)atr->Name();
			solar.p[n - 1].p[0]. or .point[i][2] = atof(atr->Value());
			//printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].p[0]. or .z[i]);
			atr = atr->Next();
		}

		pElems = pElems->NextSiblingElement(); pszNode = (char*)pElems->Value(); printf("Node: %s\n", pszNode);
		pElems = pElems->FirstChildElement(); pszNode = (char*)pElems->Value(); printf("Node: %s\n", pszNode);
		pElem = pElems;
		atr = pElem->FirstAttribute();
		//rotate
		//angle
		pszAttrib = (char*)atr->Name();
		solar.p[n - 1].p[0].r.angle = atof(atr->Value());
		printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].p[0].r.angle);
		atr = atr->Next();
		//x
		pszAttrib = (char*)atr->Name();
		solar.p[n - 1].p[0].r.x = atof(atr->Value());
		printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].p[0].r.x);
		atr = atr->Next();
		//y
		pszAttrib = (char*)atr->Name();
		solar.p[n - 1].p[0].r.y = atof(atr->Value());
		printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].p[0].r.y);
		atr = atr->Next();
		//z
		pszAttrib = (char*)atr->Name();
		solar.p[n - 1].p[0].r.z = atof(atr->Value());
		printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].p[0].r.z);

		pElem = pElem->NextSiblingElement();
		atr = pElem->FirstAttribute();

		//scale
		//r
		pszAttrib = (char*)atr->Name();
		solar.p[n - 1].p[0].s = atof(atr->Value());
		printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].p[0].s);

		pElem = pElem->NextSiblingElement();
		atr = pElem->FirstAttribute();
		//translatef
		//x
		pszAttrib = (char*)atr->Name();
		solar.p[n - 1].p[0].t.x = atof(atr->Value());
		printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].p[0].t.x);
		atr = atr->Next();
		//y
		pszAttrib = (char*)atr->Name();
		solar.p[n - 1].p[0].t.y = atof(atr->Value());
		printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].p[0].t.y);
		atr = atr->Next();
		//z
		pszAttrib = (char*)atr->Name();
		solar.p[n - 1].p[0].t.z = atof(atr->Value());
		printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].p[0].t.z);

		pElem = pElem->NextSiblingElement();
		atr = pElem->FirstAttribute();
		//color
		//r
		pszAttrib = (char*)atr->Name();
		solar.p[n - 1].p[0].c.r = atof(atr->Value());
		printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].p[0].c.r);
		atr = atr->Next();
		//g
		pszAttrib = (char*)atr->Name();
		solar.p[n - 1].p[0].c.g = atof(atr->Value());
		printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].p[0].c.g);
		atr = atr->Next();
		//b
		pszAttrib = (char*)atr->Name();
		solar.p[n - 1].p[0].c.b = atof(atr->Value());
		printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].p[0].c.b);
		//file path
		pElem = pElem->NextSiblingElement();
		atr = pElem->FirstAttribute();
		solar.p[n - 1].p[0].fpath = (char*)atr->Value();
		printf("------------Attribute: %s, Data: %s\n", pszAttrib, solar.p[n - 1].p[0].fpath);
	}
	if (ringc == 2) {
		pElems = pElems->FirstChildElement(); pszNode = (char*)pElems->Value(); printf("+++Node: %s\n", pszNode);
		pcop = pElems;
		pcop = pcop->FirstChildElement();
		atr = pcop->FirstAttribute();
		//rotate
		//angle
		pszAttrib = (char*)atr->Name();
		solar.p[n - 1].p[0].r.angle = atof(atr->Value());
		printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].p[0].r.angle);
		atr = atr->Next();
		//x
		pszAttrib = (char*)atr->Name();
		solar.p[n - 1].p[0].r.x = atof(atr->Value());
		printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].p[0].r.x);
		atr = atr->Next();
		//y
		pszAttrib = (char*)atr->Name();
		solar.p[n - 1].p[0].r.y = atof(atr->Value());
		printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].p[0].r.y);
		atr = atr->Next();
		//z
		pszAttrib = (char*)atr->Name();
		solar.p[n - 1].p[0].r.z = atof(atr->Value());
		printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].p[0].r.z);

		pcop = pcop->NextSiblingElement();
		atr = pcop->FirstAttribute();
		//sacle
		//r0
		pszAttrib = (char*)atr->Name();
		solar.p[n - 1].p[0].s = atof(atr->Value());
		printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].p[0].s);
		atr = atr->Next();
		//r1
		pszAttrib = (char*)atr->Name();
		solar.p[n - 1].p[0].sm = atof(atr->Value());
		printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].p[0].sm);
		atr = atr->Next();
		pcop = pcop->NextSiblingElement();
		atr = pcop->FirstAttribute();
		//translatef
		//x
		pszAttrib = (char*)atr->Name();
		solar.p[n - 1].p[0].t.x = atof(atr->Value());
		printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].p[0].t.x);
		atr = atr->Next();
		//y
		pszAttrib = (char*)atr->Name();
		solar.p[n - 1].p[0].t.y = atof(atr->Value());
		printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].p[0].t.y);
		atr = atr->Next();
		//z
		pszAttrib = (char*)atr->Name();
		solar.p[n - 1].p[0].t.z = atof(atr->Value());
		printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].p[0].t.z);

		pcop = pcop->NextSiblingElement();
		atr = pcop->FirstAttribute();
		//color
		//r
		pszAttrib = (char*)atr->Name();
		solar.p[n - 1].p[0].c.r = atof(atr->Value());
		printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].p[0].c.r);
		atr = atr->Next();
		//g
		pszAttrib = (char*)atr->Name();
		solar.p[n - 1].p[0].c.g = atof(atr->Value());
		printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].p[0].c.g);
		atr = atr->Next();
		//b
		pszAttrib = (char*)atr->Name();
		solar.p[n - 1].p[0].c.b = atof(atr->Value());
		printf("------------Attribute: %s, Data: %f\n", pszAttrib, solar.p[n - 1].p[0].c.b);
		//file path
		pcop = pcop->NextSiblingElement();
		atr = pcop->FirstAttribute();
		solar.p[n - 1].p[0].fpath = (char*)atr->Value();
		printf("------------Attribute: %s, Data: %s\n", pszAttrib, solar.p[n - 1].p[0].fpath);
	}
}
int readxml()
{
	TiXmlDocument doc;
	doc.LoadFile("exml.xml");
	TiXmlHandle hDoc(&doc);

	//access root node  
	TiXmlElement* pRoot = hDoc.FirstChildElement().Element();
	if (!pRoot) return 0;


	solar.p = (planet*)malloc(8 * sizeof(planet));
	solar.p[2].p = (planet*)malloc(1 * sizeof(planet));
	solar.p[5].p = (planet*)malloc(1 * sizeof(planet));
	int i = 0;
	readsun(pRoot);
	for (size_t i = 0; i <8; i++)
	{
		if (i != 2 && i != 5)readplanet(pRoot, i + 1);
	}
	readplanetandother(pRoot, 3, 1);
	readplanetandother(pRoot, 6, 2);
}

void changeSize(int w, int h) {
	if (h == 0) h = 1;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(40.0f, w / h, 1.0f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}
void reads() {
	float a;
	ifstream sunf("sphere.txt");

	while (sunf >> a)
	{
		lenght++;
	}
	sunf.clear();
	sunf.seekg(0, ios::beg);
	int j = 0;
	sun = (float*)malloc(lenght*sizeof(float));
	while (sunf >> a)
	{
		sun[j] = a;
		printf("%f", sun[j]);
		j++;

	}
	lenght = lenght / 3;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void getCatmullRomPoint(float t, int *indices, float *res, int inde) {

	// catmull-rom matrix
	float m[4][4] = { { -0.5f,  1.5f, -1.5f,  0.5f },
	{ 1.0f, -2.5f,  2.0f, -0.5f },
	{ -0.5f,  0.0f,  0.5f,  0.0f },
	{ 0.0f,  1.0f,  0.0f,  0.0f } };
	float dt[4] = { 3 * t*t,2 * t,t,1 };
	res[0] = 0.0; res[1] = 0.0; res[2] = 0.0;
	float tmp[4];
	//Isto calcula o [t^3 t^2 t 1]* M
	for (int i = 0; i < 4; i++) {
		tmp[i] = (t*t*t)*m[0][i] + (t*t)*m[1][i] + t*m[2][i] + 1 * m[3][i];
	}
	for (int j = 0; j < 3; j++)
		res[j] = tmp[0] * solar.p[inde]. or .point[indices[0]][j] + tmp[1] * solar.p[inde]. or .point[indices[1]][j] + tmp[2] * solar.p[inde]. or .point[indices[2]][j] + tmp[3] * solar.p[inde]. or .point[indices[3]][j];
}
void getGlobalCatmullRomPoint(float gt, float *res, int i) {
	float t = gt * POINT_COUNT; // this is the real global t
	int index = floor(t);  // which segment
	t = t - index; // where within  the segment
	int indices[4] = { (index + POINT_COUNT - 1) % POINT_COUNT ,
		(indices[0] + 1) % POINT_COUNT ,
		(indices[1] + 1) % POINT_COUNT ,
		(indices[2] + 1) % POINT_COUNT };
	getCatmullRomPoint(t, indices, res, i);
}
void renderCatmullRomCurve(int inde)
{
	float res[3];

	// desenhar a curva usando segmentos de reta - GL_LINE_LOOP
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 5000; i++)
	{
		getGlobalCatmullRomPoint(i / 5000.0f, res, inde);
		glVertex3f(res[0], res[1], res[2]);
	}
	glEnd();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void renderScene() {

	static float t = 0;
	float res[3];



	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(5.0 + xc, 70.0 + yc, 5.0 + zc, 0.0 +
		vc, 0.0 +
		bc, 0.0 +
		nc, 0.0f, 1.0f, 0.0f);
	glPushMatrix();

	glTranslatef(0, 0, 0);
	//	glRotatef(solar.r.a, solar.r.x, solar.r.y, solar.r.z);
	//glScalef(solar.s, solar.s, solar.s);
	glColor3f(solar.c.r, solar.c.g, solar.c.b);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, sun);
	glDrawArrays(GL_TRIANGLES, 0, lenght);
	glPopMatrix();
	for (size_t i = 0; i < 8; i++)
	{
		glPushMatrix();
		renderCatmullRomCurve(i);
		getGlobalCatmullRomPoint(solar.p[i]. or .total, res, i);
		//glRotatef(solar.p[i].r.a, solar.p[i].r.x, solar.p[i].r.y, solar.p[i].r.z);
		glColor3f(solar.p[i].c.r, solar.p[i].c.g, solar.p[i].c.b);
		glScalef(solar.p[i].s, solar.p[i].s, solar.p[i].s);
		glTranslatef(res[0] / solar.p[i].s, res[1] / solar.p[i].s, res[2] / solar.p[i].s);
		//glRotatef(solar.p[i].r.a, solar.p[i].r.x, solar.p[i].r.y, solar.p[i].r.z);
		glVertexPointer(3, GL_FLOAT, 0, sun);
		glDrawArrays(GL_TRIANGLES, 0, lenght);
		glPopMatrix();
		solar.p[i]. or .total = solar.p[i]. or .total + solar.p[i]. or .time;
	}



	glDisableClientState(GL_VERTEX_ARRAY);


	glutSwapBuffers();
}
int InitGL(GLvoid)          // All Setup For OpenGL Goes Here
{
	glShadeModel(GL_SMOOTH);       // Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);    // Black Background
	glClearDepth(1.0f);         // Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);       // Enables Depth Testing
	glDepthFunc(GL_LEQUAL);        // The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Really Nice Perspective Calculations         // Initialization Went OK
	reads();
	readxml();
	for (size_t i = 0; i < 8; i++)
	{
		solar.p[i]. or .total = 0;
	}
	solar.p[2].p[0]. or .total = 0;
	return true;          // Initialization Went OK
}
void Keys(int key, int p, int q)
{
	switch (key)
	{
	case GLUT_KEY_LEFT: xc -= 1; break;
	case GLUT_KEY_RIGHT: xc += 1; break;
	case GLUT_KEY_UP: yc += 1; break;
	case GLUT_KEY_DOWN: yc -= 1; break;
	case GLUT_KEY_F1: zc += 1; break;
	case GLUT_KEY_F2: zc -= 1; break;
	case GLUT_KEY_F3: vc += 1; break;
	case GLUT_KEY_F4: vc -= 1; break;
	case GLUT_KEY_F5: bc += 1; break;
	case GLUT_KEY_F6: bc -= 1; break;
	case GLUT_KEY_F7: nc += 1; break;
	case GLUT_KEY_F8: nc -= 1; break;
	}
}
int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);// Initial Display Mode.
	glutInitWindowPosition(100, 100);     // Position The Window
	glutInitWindowSize(640, 480);      // Window Size
	glutCreateWindow("sphere");        // Create The Window
	InitGL();           // Init OpenGL Window
	glutDisplayFunc(renderScene);      // Display Callback
	glutIdleFunc(renderScene);       // Sets The Global Idle Callback.
	glutReshapeFunc(changeSize);      // Sets The Reshape Callback 
	glutSpecialFunc(Keys);
	glutMainLoop();
	return 1;
}
