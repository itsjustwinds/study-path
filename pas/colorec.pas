{var
        a:array[-200..200,-200..200] of byte;
        dd:set of 1..4;
        ddx,ddy:array[1..100000] of integer;
        i,j,k,x,y,d,n,kq,maxx,maxy,minx,miny:longint;
procedure nhap;
begin
        readln(n);
        d:=0;
        miny:=0;maxy:=0;minx:=0;maxx:=0;
        for i:=1 to n do
        begin
                readln(x,y,k);
                a[x,y]:=k;
                if x>maxx then maxx:=x;
                if x<minx then minx:=x;
                if y>maxy then maxy:=y;
                if y<miny then miny:=y;
                if k=1 then
                begin
                        inc(d);
                        ddx[d]:=x;
                        ddy[d]:=y;
                end;
        end;
end;
procedure xuly;
begin
        kq:=0;
        for k:=1 to d do
        begin
                dd:=[1];
                for i:=minx to maxx do
                if (a[i,ddy[k]]<>0) and (not(a[i,ddy[k]] in dd)) then
                begin
                        dd:=dd+[a[i,ddy[k]]];
                        for j:=miny to maxy do
                        if (a[ddx[k],j]<>0) and (not(a[ddx[k],j] in dd)) then
                        begin
                                dd:=dd+[a[ddx[k],j]];
                                if (a[i,j]<>0) and (not(a[i,j] in dd)) then
                                        inc(kq);
                                dd:=dd-[a[ddx[k],j]];
                        end;
                        dd:=dd-[a[i,ddy[k]]];
                end;
        end;
        writeln(kq);
end;
begin
        assign(input,'colorec.inp');
        assign(output,'colorec.out');
        reset(input);
        rewrite(output);
        nhap;
        xuly;
        close(input);
        close(output);
end.
}
uses math;
var
        i,j,k,x,y,n:longint;
        kq:int64;
        a:array[-200..200,-200..200] of byte;
        c:array[1..4,1..4] of longint;
procedure nhap;
begin
        readln(n);
        fillchar(a,sizeof(a),0);
        for i:=1 to n do
        begin
                readln(x,y,k);
                a[x,y]:=k;
        end;
end;
procedure xuly;
begin
        kq:=0;
        for i:=-200 to 199 do
                for j:=i+1 to 200 do
                begin
                        fillchar(c,sizeof(c),0);
                        for k:=-200 to 200 do
                        if a[i,k]*a[j,k]>0 then
                                inc(c[min(a[i,k],a[j,k]),max(a[i,k],a[j,k])]);
                        inc(kq,c[1,2]*c[3,4]+c[1,3]*c[2,4]+c[1,4]*c[2,3]);
                end;
        writeln(kq);
end;
begin
        {assign(input,'colorec.inp');
        assign(output,'colocrec.out');
        reset(input);
        rewrite(output); }
        nhap;
        xuly;
        {close(input);
        close(output);    }
end.
