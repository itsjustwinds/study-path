uses    crt;
var
        a,b,c,gtln,n,m,i,j,t:longint;
begin   clrscr;
        write('nhap gia hoa hong,hoa lan,tien hien co:');
        readln(a,b,c);
        gtln:=0;
        n:=c div a;
        m:=c div b;
        t:=0;
        for i:=1 to n do
        for j:=1 to m do
        begin
        t:=0;
        if a*i+b*j<=c then
                begin
                        if (a*i+b*j>gtln) and (i+j>t) then
                                begin
                                        gtln:=a*i+b*j;
                                        t:=i+j;
                                end;
                end;
        end;
        write('gia tien lon nhat la:',gtln);
        readln
end.



