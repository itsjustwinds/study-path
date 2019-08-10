 var    a:array [1..100,1..100] of integer;
        n,i,j,m,min,t:longint;
 begin
        write('nhap so hang, so cot');
        readln(m,n);
        t:=0;
        for i:=1 to m do
                for j:=1 to n do
                        begin
                                write('nhap a[',i,',',j,']');
                                readln(a[i,j]);
                        end;
                        min:=a[1,1];
        for i:=1 to m do
        begin
                for j:=1 to n do write(a[i,j]:4);
                writeln;
        end;
        writeln;
        for i:=1 to m do
                for j:=1 to n do
                        if a[i,j]<min then min:=a[i,j];
        writeln('phan tu nho nhat la:',min);
        for i:=1 to m do
                begin
                        for j:=1 to n do
                        t:=t+a[i,j];
                        writeln('tong cac phan tu dong thu ',i,' la:',t);
                        t:=0;
                end;
        readln
 end.


