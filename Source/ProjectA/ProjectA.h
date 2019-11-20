// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(ProjectA, Log, All);
// �ڵ尡 ����ִ� ���� �̸��� �Լ�, �߰� �����α׸� �����.
#define PROJECT_LOG_CALLINFO (FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__) + TEXT(")"))
// ������ ���� ���ڿ��� �߰� ������ ������ �α׸� �����.
#define PROJECT_LOG_S(Verbosity) UE_LOG(ProjectA, Verbosity, TEXT("%s"), *PROJECT_LOG_CALLINFO)
#define PROJECT_LOG(Verbosity, Format, ...) UE_LOG(ProjectA, Verbosity, TEXT("%s %s"), *PROJECT_LOG_CALLINFO, *FString::Printf(Format, ##__VA_ARGS__))

#define CHECKASSERT(Expr, ...) {if(!(Expr)) { PROJECT_LOG(Error, TEXT("ASSERTION: %s"), TEXT("'"#Expr"'")); return __VA_ARGS__; }}