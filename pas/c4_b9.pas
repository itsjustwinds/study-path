uses crt;
var
        n:longint;
begin
        clrscr;
        write('nhap n:');
        readln(n);
                if (n mod 2<>0) and (n<2) then write('n ko la so nguyem to');
                if( n mod 2=0)and (n>2) or (n mod 3=0)and (n>2) then write('n ko la so nguyen to');
                if(n mod 2<>0)and(n mod 3<>0) and (n>2) then write('n la so nguyen to');
                if(n mod 2=0)and (n<=2) then write('n la so nguyen to');
        readln
end.
