// TrainLab.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "LoggerFactory.h"
#include "Train.h"

int main()
{
	LoggerFactory factory;
	ILogger* logger = factory.Create(Console);
	Train train(logger);
	train.Count();
	int a;
	cin >> a;
}

