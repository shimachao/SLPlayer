#pragma once
#include "AbstractView.h"
#include "AbstractController.h"

class AbstractControl:public AbstractView,public AbstractController
{
public:
	AbstractControl() = default;
	~AbstractControl() = default;
};
