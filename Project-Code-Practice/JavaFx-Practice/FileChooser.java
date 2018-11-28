/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gopro;

import java.awt.Color;
import java.awt.Desktop;
import java.awt.Font;
import static java.awt.Font.CENTER_BASELINE;
import java.io.File;
import java.io.IOException;
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.*;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;
import javafx.scene.*;
import javafx.scene.control.TextField;
import javafx.stage.FileChooser;
import javafx.stage.FileChooser.ExtensionFilter;

/**
 *
 * @author fsshakkhor
 */
public class GoPro extends Application {
    
    private Desktop desktop = Desktop.getDesktop();
    @Override public void start(Stage primaryStage) throws IOException {
        primaryStage.setTitle("Some Kind of Application");

        FileChooser fileChooser = new FileChooser();
        fileChooser.setTitle("Open Resource File");
        
        fileChooser.getExtensionFilters().addAll(
        new ExtensionFilter("Text Files", "*.txt"),
        new ExtensionFilter("Image Files", "*.png", "*.jpg", "*.gif"),
        new ExtensionFilter("Audio Files", "*.wav", "*.mp3", "*.aac"),
        new ExtensionFilter("All Files", "*.*"));
        
            
        File selectedFile = fileChooser.showOpenDialog(primaryStage);
        if (selectedFile != null) {
             desktop.open(selectedFile);
        }

    }

    public static void main(String[] args) {
        launch(args);
    }
    
}
