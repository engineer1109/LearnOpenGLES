package com.engineer1109.openglesdemo.viewmodel;

import android.annotation.SuppressLint;
import android.content.Context;
import android.content.Intent;
import android.view.View;

import androidx.lifecycle.ViewModel;
import androidx.recyclerview.widget.LinearLayoutManager;

import com.engineer1109.openglesdemo.MainActivity;
import com.engineer1109.openglesdemo.R;
import com.engineer1109.openglesdemo.activities.BaseRenderActivity;
import com.engineer1109.openglesdemo.adapters.MenuAdapter;
import com.engineer1109.openglesdemo.databinding.ActivityMainBinding;
import com.engineer1109.openglesdemo.itemdecoration.VerticalRecyclerItemDecoration;
import com.engineer1109.openglesdemo.model.MenuData;

import java.util.ArrayList;
import java.util.List;

public class MainViewModel extends ViewModel {

    static final String TAG = "MainViewModel";

    private ActivityMainBinding mBinding = null;

    public ActivityMainBinding getBinding() {
        return mBinding;
    }

    public void setBinding(ActivityMainBinding mBinding) {
        this.mBinding = mBinding;
    }

    public Context getContext() {
        return mBinding.getRoot().getContext();
    }

    @SuppressLint("ResourceAsColor")
    public void showMenu(View view) {
        List<MenuData> datas = this.generateMenus();
        Context context = view.getContext();
        mBinding.rcMenu.setLayoutManager(new LinearLayoutManager(view.getContext()));
        mBinding.rcMenu.addItemDecoration(new VerticalRecyclerItemDecoration(R.color.black, 0));
        mBinding.rcMenu.setAdapter(new MenuAdapter(datas) {
            @Override
            public void convert(VH holder, MenuData data, final int position) {
                holder.setText(R.id.btn_menu, data.getMenuText());
                holder.getView(R.id.btn_menu).setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
                        Intent intent = new Intent(getContext(), BaseRenderActivity.class);
                        intent.putExtra("ID", position);
                        getContext().startActivity(intent);
                    }
                });
            }
        });
    }

    private List<MenuData> generateMenus() {
        List<MenuData> datas = new ArrayList<>();
        {
            MenuData data = new MenuData();
            data.setID(1);
            data.setMenuText("Triangle");
            datas.add(data);
        }
        {
            MenuData data = new MenuData();
            data.setID(2);
            data.setMenuText("Texture2DCube");
            datas.add(data);
        }
        return datas;
    }
}
