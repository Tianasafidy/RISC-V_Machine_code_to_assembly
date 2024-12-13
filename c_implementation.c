uint32_t foo(uint32_t * a0, uint32_t * a1, uint32_t * a2, uint32_t a3){
	uint32_t * a7 = a0; 
	if(a7 == NULL)
		return 4095; 
	if(a1 == NULL)
		return 4095; 
	if(a2 == NULL)
		return 4095; 
	if(a3 <= 0)
		return a3;

 
	uint32_t * a5 = a7; // a5 prend l'adresse de a0; 
	uint32_t a4 = a3 * 4; 
	
	a7 += a4;
	
	a4 = *a5; //valeur poingter par  a0 
	uint32_t a6 = *a1; //valeur pointer par a1 
 
	a4 = a4 + a6; // somme des valeur pointer par a0 et a1
	*a2 = a4 ; // on stocke la somme des valeur pointer par a0 et a1 dans la case mémoire pointer par a2 
	a5 += 4; //on avance de 4 bytes depuis a0
	a1 += 4; //on avance de 4 bytes depuis a1 
	a2 += 4; //on avance de 4 bytes depuis a2 
	
	if(a5 != a7) //si les deux pointeurs ne pointent pas vers la même case adresse  
		return ERROR_DS_ADMIN; //return errors
	
	return a3; 
}
