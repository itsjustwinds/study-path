uses crt;
var
        i,n,tu:longint;
begin   clrscr;
        write('nhap n:');
        readln(n);
        tu:=0;
        for i:=1 to n-1 do
        if (n mod i=0) then        tu:=tu+i;
        if tu=n then write('so n la so hoan hao')
        else
        write('so n khong la so hoan hao');
        readln
end.