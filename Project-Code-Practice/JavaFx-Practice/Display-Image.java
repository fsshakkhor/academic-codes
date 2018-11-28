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
import java.awt.image.BufferedImage;
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
import javafx.scene.image.ImageView;
import javafx.scene.image.PixelWriter;
import javafx.scene.image.WritableImage;
import javafx.stage.FileChooser;
import javafx.stage.FileChooser.ExtensionFilter;
import javax.imageio.ImageIO;

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
        new ExtensionFilter("All Files", "*.*"));
        
            
        File selectedFile = fileChooser.showOpenDialog(primaryStage);
        if (selectedFile != null) {
            BufferedImage image = ImageIO.read(selectedFile);
            int height = image.getHeight();
            int width = image.getWidth();
            
            WritableImage wr = new WritableImage(width, height);
            PixelWriter pw = wr.getPixelWriter();
            for(int i = 0;i < width;i++){
                for(int j = 0;j < height;j++){
                    pw.setArgb(i,j,image.getRGB(i, j));
                }
            }
            System.out.println(height + " " + width);
            StackPane root = new StackPane();
            ImageView imView = new ImageView(wr);
            root.getChildren().add(imView);
            Scene scene = new Scene(root,1000,1000);
            primaryStage.setScene(scene);
            primaryStage.show();;
        }

    }

    public static void main(String[] args) {
        launch(args);
    }
    
}
