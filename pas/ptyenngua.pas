const
        fi='ptyenngua.inp';
        fo='ptyenngua.out';
var
        a:array [1..50,1..50] of longint;
        m,n,i,j,min,max,h,y,x,c,v:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        read(f,m,n);
        for i:=1 to m do
        begin
                for j:=1 to n do
                        read(f,a[i,j]);
                readln(f);
        end;
        close(f);
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        for i:=1 to m do
        begin
                for j:=1 to n do
                begin
                        max:=a[i,j];
                        min:=a[i,j];
                        x:=i;
                        y:=j;
                        for h:=1 to m do
                                if a[h,j]>max then
                                begin
                                        max:=a[h,j];
                                        x:=h;
					c:=j;
                                end;
                        for h:=1 to n do
                                if a[i,h]<min then
                                begin
                                        min:=a[i,h];
					v:=i;
                                        y:=h;
                                end;
                        if (x=v) and (c=y){ and (min=max)} then writeln(f,'yen ngua o dong ',x,' cot ',y,' co gia tri la ',a[x,y]);
                end;
        end;
        close(f);
end;
begin
        nhap;
        xuat;
end.
