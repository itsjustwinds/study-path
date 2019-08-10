var     a:array[1..100,1..100] of longint;
        b:array[1..10000] of longint;
        i,j,m,n,tam,dem:longint;
begin
        for i:=1 to m do
                for j:=1 to n do
                        write('nhap gia tri');
                        readln(a[i,j]);
        dem:=0;
        for i:=1 to m do
                for j:=1 to n do
                        begin
                                dem:=dem+1;
                                b[dem]:=a[i,j];
                        end;
        for i:=1 to dem div 2 do
                for j:=dem downto dem div 2 do
                        if b[i]>b[j] then
                                begin
                                        tam:=b[i];
                                        b[i]:=b[j];
                                        b[j]:=tam;
                                end;
        dem:=1;
        for i:=1 to m do
                for j:=1 to n do
                        begin
                                a[i,j]:=b[dem];
                                dem:=dem+1;
                        end;
        for i:=1 to m do
                begin
                        for j:=1 to n do
                                write(a[i,j]:4);
                        writeln;
                end;
        readln
end.



