const
        fi='luoi.inp';
        fo='luoi.out';
var
        a,l,b:array[0..1001,0..1001] of longint;
        i,j,d,n,m,g,h,itmp,jtmp:longint;
        kt:boolean;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n,m);
        readln(f,g,h);
        for i:=1 to n do
                for j:=1 to m do
                        read(f,a[i,j]);
        close(f);
end;
function max(a,b,c:longint):longint;
begin
        if a>b then max:=a
        else max:=b;
        if max<c then max:=c;
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        g:=n-g;
        h:=h+1;
        l[1,1]:=0;
        for i:=n-1 downto g do
                if a[i,1]<>0 then b[i,1]:=b[i+1,1]+1
                else break;
        for i:=2 to h do
                if a[n,i]<>0 then b[n,i]:=b[n,i-1]+1
                else break;
        for i:=n-1 downto g do
                for j:=2 to h do
                        if a[i,j]=1 then
                                if ((b[i+1,j]<>0) or(b[i+1,j-1]<>0) or (b[i,j-1]<>0)) or ((i=2) and(j=2)) then
                        begin
                                itmp:=0;jtmp:=0;
                                l[i,j]:=max(l[i+1,j],l[i+1,j-1]+1,l[i,j-1]);
                                begin
                                if (max(l[i+1,j],l[i+1,j-1]+1,l[i,j-1])=l[i+1,j]) and (a[i+1,j]=1) then
                                begin
                                        b[i,j]:=b[i+1,j]+1;
                                        break;
                                end;
                                if (max(l[i+1,j],l[i+1,j-1]+1,l[i,j-1])=l[i+1,j-1]) and (a[i+1,j-1]=1) then
                                begin
                                        b[i,j]:=b[i+1,j-1]+1;
                                        break;
                                end;
                                 if (max(l[i+1,j],l[i+1,j-1]+1,l[i,j-1])=l[i,j-1]) and (a[i,j-1]=1) then
                                 begin
                                        b[i,j]:=b[i,j-1]+1;
                                        break;
                                 end;
                                 end;
                        end;
       { write(f,b[g,h],' ',l[g,h]);}
      { for i:=n downto g do
       begin
        for j:=1 to h do
                write(f,a[i,j],' ');
                writeln(f);
        end;            }
        for i:=1 to n do
        begin
                for j:=1 to m do
                        write(f,b[i,j],' ');
                writeln(f);
        end;
        close(f);
end;
begin
        nhap;
        xuly;
end.
