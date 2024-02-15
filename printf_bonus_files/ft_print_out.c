#include "../ft_printf.h"

//evrth formated according to the res, just print
void	ft_print_out(t_printf *d)
{
	ft_total_print_l(d);
	if (!d->flags->minus)
	{
		if (*d->curr_s == 's' && d->flags->zero)
			ft_fill_char('0', d->flags->width);
		else
			ft_fill_char(' ', d->flags->width);
	}
	write(1, "+", d->flags->plus);
	write(1, " ", d->flags->space);
	if (d->flags->negative && (*d->curr_s == 'd' || *d->curr_s == 'i'))
		write(1, "-", 1);
	ft_hash_ident(d);
	ft_fill_char('0', d->flags->dot);
	write(1, d->f_print, d->f_print_l);
	if (d->flags->minus)
		ft_fill_char(' ', d->flags->width);
}