uses crt;
var
        n,i,s,dem:longint;
begin   clrscr;
        write('nhap n:');
        readln(n)
        s:=0;
        dem:=0;
        writeln('cac uoc so chan la');
        for i:=1 to n do
        if(i mod 2=0)and (n mod i=0) then
        begin
                write(i,' ');
                s:=s+i;
                dem:=dem+1;
        end;
        writeln;
        write('s la:',s);
        readln;
        write('dem la:',dem);
        readln
end.
