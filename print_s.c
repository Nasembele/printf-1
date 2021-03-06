/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniki <lniki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:57:25 by lniki             #+#    #+#             */
/*   Updated: 2020/03/17 16:36:10 by lniki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    if_no_minus_s(t_pr *mod, char *s)
{
    if(mod->precf >= 0 && mod->precf < (int)ft_strlen(s))
        write(1, s, mod->precf);
    else
            write(1, s, ft_strlen(s));
}

void    if_minus_s(t_pr *mod, char *s)
{
        if(mod->precf >= 0 && mod->precf < (int)ft_strlen(s))
            write(1, s, mod->precf); 
        else
            write(1, s, ft_strlen(s));
}

void    print_s(t_pr *mod)
{
    char *s;
    
    s = va_arg(*(mod->ap), char *);
    if(!s)
        s = "(null)"; 
    if((mod->wdtx > mod->precf && mod->precf >= 0) 
        || mod->wdtx > (int)ft_strlen(s))
        mod->nprinted += mod->wdtx;
    else if ((mod->precf >= 0 && mod->precf < (int)ft_strlen(s)))
        mod->nprinted += mod->precf;
    else
        mod->nprinted += ft_strlen(s);
    if(mod->minus == 1)
        if_minus_s(mod, s);
    while((mod->wdtx > mod->precf && mod->precf >= 0) 
        || mod->wdtx > (int)ft_strlen(s))
    {    
        write(1," ", 1);
        mod->wdtx--;
    }
    if(mod->minus == 0)
        if_no_minus_s(mod, s);
}